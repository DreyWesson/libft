
// export const handleApp = (app) => {
//     const todoInput = app.querySelector("#todo-input");
//     const searchIcon = app.querySelector("#search-todo");
//     const addBtn = app.querySelector("#add-todo");
//     const filterField = app.querySelector("#filter-input");
//     const listTodo = app.querySelector("#todo-list");
  
//     let todoList = [];
  
//     addBtn.addEventListener("click", (e) => {
//       addTodo();
//     });
  
//     todoInput.addEventListener("keypress", (e) => {
//       if (e.key === "Enter") {
//         addTodo();
//       }
//     });
  
//     searchIcon.addEventListener("click", searchTodo);
  
//     filterField.addEventListener("change", filterTodo);
  
//     function filterTodo() {
//       console.log(filterField.value)
//       let todo;
//       if (filterField.value === "active")
//         todo =todoList.filter((todo) => !todo.completed)
//       else if (filterField.value === "completed")
//         todo = todoList.filter((todo) => todo.completed);
//       else {
//         renderTodo(todoList);
//         return;
//       }
    
//       renderTodo(todo)
//     }
  
//     function addTodo() {
//       const text = todoInput.value.trim();
//       if (text === "") return;
  
//       const todo = {
//         text,
//         id: Date.now(),
//         completed: false,
//         createdAt: new Date(),
//         updatedAt: new Date(),
//       };
//       todoList.push(todo);
//       renderTodo(todoList);
//       todoInput.value = "";
//     }
  
//     function searchTodo() {
//       const input = todoInput.value.trim().toLowerCase();
//       const searched = todoList.filter((todo) =>
//         todo.text.toLowerCase().includes(input)
//       );
//       renderTodo(searched)
//     }
  
//     function deleteTodo(id) {
//       todoList = todoList.filter((todo) => todo.id !== id);
//       renderTodo(todoList);
//     }
  
//     function toggleComplete(id) {
//       todoList = todoList.map((todo) => {
//         if (todo.id === id) {
//           todo = { ...todo, completed: !todo.completed };
//         }
//         return todo;
//       });
//       renderTodo(todoList);
//     }
  
//     function updateTodo(id) {
//       const text = prompt("Update your todo");
//       if (text) {
//         todoList = todoList.map((todo) => {
//           if (todo.id == id) {
//             todo = {
//               ...todo,
//               text,
//               updatedAt: Date.now(),
//             };
//           }
//           return todo;
//         });
//         renderTodo(todoList);
//       }
//     }
  
//     function renderTodo(todoArr) {
//       // li
//       listTodo.innerHTML = "";
//       todoArr.forEach((todo) => {
//         const li = document.createElement("li");
//         li.classList.toggle("completed", todo.completed);
//         // checkbox
//         const checkbox = document.createElement("input");
//         checkbox.type = "checkbox";
//         checkbox.classList.add("checkbox");
//         checkbox.checked = todo.completed;
//         checkbox.addEventListener("change", () => {
//           toggleComplete(todo.id);
//         });
//         // span
//         const text = document.createElement("span");
//         text.classList.add("todo-text");
//         text.textContent = todo.text;
  
//         // edit btn
//         const editBtn = document.createElement("button");
//         editBtn.textContent = "Edit";
//         editBtn.classList.add("edit-btn");
//         editBtn.addEventListener("click", (e) => {
//           e.stopPropagation();
//           updateTodo(todo.id);
//         });
//         // delete btn
//         const deleteBtn = document.createElement("button");
//         deleteBtn.textContent = "Delete";
//         deleteBtn.classList.add("delete-btn");
//         deleteBtn.addEventListener("click", (e) => {
//           e.stopPropagation();
//           deleteTodo(todo.id);
//         });
//         // append
//         li.appendChild(checkbox);
//         li.appendChild(text);
//         li.appendChild(editBtn);
//         li.appendChild(deleteBtn);
//         listTodo.appendChild(li);
//       });
//     }
//   };
  
// todo.module.js

export const Todo = (function() {
  return (app) => {
      const todoInput = app.querySelector("#todo-input");
      const searchIcon = app.querySelector("#search-todo");
      const addBtn = app.querySelector("#add-todo");
      const filterField = app.querySelector("#filter-input");
      const listTodo = app.querySelector("#todo-list");
      let todoList = [];

      addBtn.addEventListener("click", addTodo);
      todoInput.addEventListener("keypress", (e) => {
          if (e.key === "Enter") addTodo();
      });
      searchIcon.addEventListener("click", searchTodo);
      filterField.addEventListener("change", filterTodo);

      function addTodo() {
          const text = todoInput.value.trim();
          if (text === "") return;

          const todo = {
              text,
              id: Date.now(),
              completed: false,
              createdAt: new Date(),
              updatedAt: new Date(),
          };
          todoList.push(todo);
          renderTodo(todoList);
          todoInput.value = "";
      }

      function filterTodo() {
          let filteredTodos;
          if (filterField.value === "active") {
              filteredTodos = todoList.filter((todo) => !todo.completed);
          } else if (filterField.value === "completed") {
              filteredTodos = todoList.filter((todo) => todo.completed);
          } else {
              filteredTodos = todoList;
          }

          renderTodo(filteredTodos);
      }

      function searchTodo() {
          const input = todoInput.value.trim().toLowerCase();
          const searched = todoList.filter((todo) =>
              todo.text.toLowerCase().includes(input)
          );
          renderTodo(searched);
      }

      function deleteTodo(id) {
          todoList = todoList.filter((todo) => todo.id !== id);
          renderTodo(todoList);
      }

      function toggleComplete(id) {
          todoList = todoList.map((todo) => {
              if (todo.id === id) {
                  todo.completed = !todo.completed;
              }
              return todo;
          });
          renderTodo(todoList);
      }

      function updateTodo(id) {
          const text = prompt("Update your todo");
          if (text) {
              todoList = todoList.map((todo) => {
                  if (todo.id === id) {
                      todo.text = text;
                      todo.updatedAt = new Date();
                  }
                  return todo;
              });
              renderTodo(todoList);
          }
      }

      function renderTodo(todoArr) {
          listTodo.innerHTML = "";
          todoArr.forEach((todo) => {
              const li = document.createElement("li");
              li.classList.toggle("completed", todo.completed);
              const checkbox = document.createElement("input");
              checkbox.type = "checkbox";
              checkbox.classList.add("checkbox");
              checkbox.checked = todo.completed;
              checkbox.addEventListener("change", () => toggleComplete(todo.id));
              const text = document.createElement("span");
              text.classList.add("todo-text");
              text.textContent = todo.text;
              const editBtn = document.createElement("button");
              editBtn.textContent = "Edit";
              editBtn.classList.add("edit-btn");
              editBtn.addEventListener("click", (e) => {
                  e.stopPropagation();
                  updateTodo(todo.id);
              });
              const deleteBtn = document.createElement("button");
              deleteBtn.textContent = "Delete";
              deleteBtn.classList.add("delete-btn");
              deleteBtn.addEventListener("click", (e) => {
                  e.stopPropagation();
                  deleteTodo(todo.id);
              });
              li.appendChild(checkbox);
              li.appendChild(text);
              li.appendChild(editBtn);
              li.appendChild(deleteBtn);
              listTodo.appendChild(li);
          });
      }
  }
})();
