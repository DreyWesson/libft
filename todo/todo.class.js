export class Todo {
    constructor(app) {
        this.app = app
        this.todoInput = app.querySelector("#todo-input");
        this.searchIcon = app.querySelector("#search-todo");
        this.addBtn = app.querySelector("#add-todo");
        this.filterField = app.querySelector("#filter-input");
        this.listTodo = app.querySelector("#todo-list");
        this.todoList = [];

        this.addBtn.addEventListener("click", () => this.addTodo);
        this.todoInput.addEventListener("keypress", (e) => (e.key === "Enter") && this.addTodo());
        this.searchIcon.addEventListener("click", () => this.searchTodo);
        this.filterField.addEventListener("change", () => this.filterTodo);
    }

    addTodo() {
        const text = this.todoInput.value.trim();
        if (text === "") return;
    
        const todo = {
          text,
          id: Date.now(),
          completed: false,
          createdAt: new Date(),
          updatedAt: new Date(),
        };
        this.todoList.push(todo);
        this.renderTodo(todoList);
        this.todoInput.value = "";
      }

      filterTodo() {
        let todo;
        if (this.filterField.value === "active")
          todo = this.todoList.filter((todo) => !todo.completed)
        else if (this.filterField.value === "completed")
          todo = this.todoList.filter((todo) => todo.completed);
        else {
          this.renderTodo(todoList);
          return;
        }
      
        this.renderTodo(todo)
      }

    searchTodo() {
        const input = this.todoInput.value.trim().toLowerCase();
        const searched = this.todoList.filter((todo) =>
          todo.text.toLowerCase().includes(input)
        );
        this.renderTodo(searched)
      }

    deleteTodo(id) {
        this.todoList = this.todoList.filter((todo) => todo.id !== id);
        this.renderTodo(this.todoList);
      }

    toggleComplete(id) {
        this.todoList = this.todoList.map((todo) => {
          if (todo.id === id) {
            todo = { ...todo, completed: !todo.completed };
          }
          return todo;
        });
        this.renderTodo(this.todoList);
      }

    updateTodo(id) {
        const text = prompt("Update your todo");
        if (text) {
          this.todoList = this.todoList.map((todo) => {
            if (todo.id == id) {
              todo = {
                ...todo,
                text,
                updatedAt: Date.now(),
              };
            }
            return todo;
          });
          this.renderTodo(this.todoList);
        }
      }

    renderTodo(todoArr) {
        // li
        this.listTodo.innerHTML = "";
        todoArr.forEach((todo) => {
          const li = document.createElement("li");
          li.classList.toggle("completed", todo.completed);
          // checkbox
          const checkbox = document.createElement("input");
          checkbox.type = "checkbox";
          checkbox.classList.add("checkbox");
          checkbox.checked = todo.completed;
          checkbox.addEventListener("change", () => 
            this.toggleComplete(todo.id));
          // span
          const text = document.createElement("span");
          text.classList.add("todo-text");
          text.textContent = todo.text;
    
          // edit btn
          const editBtn = document.createElement("button");
          editBtn.textContent = "Edit";
          editBtn.classList.add("edit-btn");
          editBtn.addEventListener("click", (e) => {
            e.stopPropagation();
            this.updateTodo(todo.id);
          });
          // delete btn
          const deleteBtn = document.createElement("button");
          deleteBtn.textContent = "Delete";
          deleteBtn.classList.add("delete-btn");
          deleteBtn.addEventListener("click", (e) => {
            e.stopPropagation();
            this.deleteTodo(todo.id);
          });
          // append
          li.appendChild(checkbox);
          li.appendChild(text);
          li.appendChild(editBtn);
          li.appendChild(deleteBtn);
          this.listTodo.appendChild(li);
        });
      }
}