//测试点3、5 未通过
import java.util.HashMap;
import java.util.Scanner;

public class Main {
	static HashMap<Integer, Tree> map = new HashMap<>();

	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		int m = scanner.nextInt();
		int n = scanner.nextInt();
		int[] inorder = new int[n];
		int[] preorder = new int[n];
		for (int i = 0; i < n; i++) {
			inorder[i] = scanner.nextInt();
		}
		for (int i = 0; i < n; i++) {
			preorder[i] = scanner.nextInt();
		}
		Tree tree = formTreeWithInAndPreOrder(null, inorder, 0, preorder, 0, n);
		for (int i = 0; i < m; i++) {
			int u = scanner.nextInt();
			int v = scanner.nextInt();
			if (!map.containsKey(u)) {
				if (!map.containsKey(v))
					System.out.println("ERROR: " + u + " and " + v + " are not found.");
				else
					System.out.println("ERROR: " + u + " is not found.");
			} else {
				if (!map.containsKey(v))
					System.out.println("ERROR: " + v + " is not found.");
				else {
					boolean isUDeeper = true;
					Tree ut = map.get(u);
					Tree vt = map.get(v);
					while (ut.depth > vt.depth) {
						ut = ut.parent;
					}
					while (vt.depth > ut.depth) {
						isUDeeper = false;
						vt = vt.parent;
					}
					if(ut==vt) {
						if (isUDeeper)
							System.out.println(v + " is an ancestor of " + u + ".");
						else
							System.out.println(u + " is an ancestor of " + v + ".");
						continue;
					}
					while (ut != vt) {
						ut = ut.parent;
						vt = vt.parent;
					}
					System.out.println("LCA of " + u + " and " + v + " is " + ut.val + ".");
				}
			}
		}

		scanner.close();
	}

	private static Tree formTreeWithInAndPreOrder(Tree parent, int[] inorder, int inFrom, int[] preorder,
			int preFrom, int num) {
		int rootIndex = -1;
		for (int i = inFrom; i < inFrom + num; i++) {
			if (inorder[i] == preorder[preFrom]) {
				rootIndex = i;
				break;
			}
		}
		Tree res = new Tree(preorder[preFrom], parent, parent==null?0:parent.depth+1);
		map.put(preorder[preFrom], res);
		if (rootIndex < inFrom + num - 1)
			res.right = formTreeWithInAndPreOrder(res, inorder, rootIndex + 1, preorder,
					preFrom - inFrom + rootIndex + 1, inFrom + num - rootIndex - 1);
		if (rootIndex > inFrom)
			res.left = formTreeWithInAndPreOrder(res, inorder, inFrom, preorder, preFrom + 1,
					rootIndex - inFrom);
		return res;
	}
}

class Tree {
	int val;
	Tree left;
	Tree right;
	Tree parent;
	int depth;

	Tree(int val, Tree parent, int depth) {
		this.val = val;
		this.parent = parent;
		this.depth = depth;
	}
}
