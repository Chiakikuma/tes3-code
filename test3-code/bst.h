#pragma once

template <typename K, typename T>
class BST {
protected:
	class Node {
	public:
		Node(const K& k, const T& d) 
			{ key = k; data = d; left = right = nullptr; }
		K key;
		T data;
		Node* left;
		Node* right;
	};
	Node* root;
	T& get(Node* p, const K& k);
	bool insert(Node* p, const K& k, const T& d);
	bool is_key(Node* p, const K& k);
	bool replace(Node* p, const K& k, const T& d);

	template <typename U>
	void inorder(Node* p, U& f) const {
		if (!p) return;
		inorder(p->left, f);
		f(p->key, p->data);
		inorder(p->right, f);
	}
public:
	BST() { root = nullptr; }
	T& get(const K& k) { return get(root, k); }
	bool insert(const K& k, const T& d);
	bool is_key(const K& k) { return is_key(root, k); }
	bool replace(const K& k, const T& d) { return replace(root, k, d); }

	template <typename U>
	U inorder(U f) const { U g = U(f); inorder(root, g); return g; }

	T& operator[] (const K& k) { if (!is_key(k)) insert(k, T()); return get(k); }
};

template <typename K, typename T>
T& BST<K, T>::get(Node* p, const K& k) {
	if (p->key == k)
		return p->data;
	if (k < p->key)
		return get(p->left, k);
	return get(p->right, k);
}

template <typename K, typename T>
bool BST<K, T>::insert(const K& k, const T& d) {
	if (root)
		return insert(root, k, d);
	root = new Node(k, d);
	return true;
}

template <typename K, typename T>
bool BST<K, T>::insert(Node* p, const K& k, const T& d) {
	if (k == p->key)
		return false;
	if (k < p->key) {
		// insert to left sub-tree
		if (p->left)
			return insert(p->left, k, d);
		p->left = new Node(k, d);
		return true;
	}
	// insert to right sub-tree
	if (p->right)
		return insert(p->right, k, d);
	p->right = new Node(k, d);
	return true;
}

template <typename K, typename T>
bool BST<K, T>::is_key(Node* p, const K& k) {
	if (!p)
		return false;
	if (k == p->key)
		return true;
	if (k < p->key)
		return is_key(p->left, k);
	return is_key(p->right, k);
}

template <typename K, typename T>
bool BST<K, T>::replace(Node* p, const K& k, const T& d) {
	if (!p)
		return false;
	if (p->key == k) {
		p->data = d;
		return true;
	}
	if (k < p->key)
		return replace(p->left, k, d);
	return replace(p->right, k, d);
}
