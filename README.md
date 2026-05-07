# Directory & File Manager (BST Implementation)

A hierarchical File Management System simulation developed in C++. This project uses a **Binary Search Tree (BST)** to organize files and directories, allowing for efficient searching, insertion, and deletion based on alphabetical order.

## 🚀 Features
- **Create:** Add new files or directories.
- **Delete:** Remove existing files or directories (handles leaf, single-child, and two-children nodes).
- **Search:** Quickly locate a file or directory by name in $O(\log n)$ average time.
- **Traversals:** 
  - **In-order:** Lists all files/folders in alphabetical order.
  - **Pre-order:** Displays the tree structure (useful for backups).
  - **Post-order:** Useful for calculating total directory size or recursive deletion.

## 📂 Project Structure
Each node in the tree represents a file system entity:
- `name`: The string identifier (e.g., "Documents").
- `isDir`: A boolean flag (True for Directory, False for File).
- `left` / `right`: Pointers to child nodes in the BST.



## 🛠️ Installation & Usage

1. **Clone the repository:**
   ```bash
   git clone [https://github.com/YOUR_USERNAME/File-Manager-BST.git](https://github.com/YOUR_USERNAME/File-Manager-BST.git)
