import '@testing-library/jest-dom/extend-expect';
import { fireEvent } from '@testing-library/dom';
import handleApp from './path-to-your-handleApp.js'; // Update with the correct path

const createMockApp = () => {
  const app = document.createElement('div');
  app.innerHTML = `
    <input id="todo-input" />
    <button id="add-todo">Add Todo</button>
    <button id="search-todo">Search</button>
    <select id="filter-input">
      <option value="all">All</option>
      <option value="active">Active</option>
      <option value="completed">Completed</option>
    </select>
    <ul id="todo-list"></ul>
  `;
  return app;
};

describe('handleApp', () => {
  let app;
  let todoInput;
  let addBtn;
  let searchIcon;
  let filterField;
  let listTodo;

  beforeEach(() => {
    app = createMockApp();
    document.body.appendChild(app);
    handleApp(); // Initialize the app

    todoInput = app.querySelector('#todo-input');
    addBtn = app.querySelector('#add-todo');
    searchIcon = app.querySelector('#search-todo');
    filterField = app.querySelector('#filter-input');
    listTodo = app.querySelector('#todo-list');
  });

  afterEach(() => {
    document.body.removeChild(app);
  });

  test('adds a todo item', () => {
    todoInput.value = 'Test Todo';
    fireEvent.click(addBtn);

    const todos = listTodo.querySelectorAll('li');
    expect(todos).toHaveLength(1);
    expect(todos[0]).toHaveTextContent('Test Todo');
  });

  test('toggles todo completion', () => {
    todoInput.value = 'Test Todo';
    fireEvent.click(addBtn);

    const checkbox = listTodo.querySelector('input[type="checkbox"]');
    fireEvent.click(checkbox);

    expect(checkbox).toBeChecked();
  });

  test('deletes a todo item', () => {
    todoInput.value = 'Test Todo';
    fireEvent.click(addBtn);

    const deleteBtn = listTodo.querySelector('.delete-btn');
    fireEvent.click(deleteBtn);

    const todos = listTodo.querySelectorAll('li');
    expect(todos).toHaveLength(0);
  });

  test('updates a todo item', () => {
    todoInput.value = 'Test Todo';
    fireEvent.click(addBtn);

    const editBtn = listTodo.querySelector('.edit-btn');
    window.prompt = jest.fn().mockReturnValue('Updated Todo');
    fireEvent.click(editBtn);

    const todos = listTodo.querySelectorAll('li');
    expect(todos[0]).toHaveTextContent('Updated Todo');
  });

  test('filters todo items', () => {
    todoInput.value = 'Test Todo 1';
    fireEvent.click(addBtn);
    todoInput.value = 'Test Todo 2';
    fireEvent.click(addBtn);

    const checkbox = listTodo.querySelectorAll('input[type="checkbox"]')[0];
    fireEvent.click(checkbox); // Mark the first todo as completed

    fireEvent.change(filterField, { target: { value: 'active' } });
    let todos = listTodo.querySelectorAll('li');
    expect(todos).toHaveLength(1);
    expect(todos[0]).toHaveTextContent('Test Todo 2');

    fireEvent.change(filterField, { target: { value: 'completed' } });
    todos = listTodo.querySelectorAll('li');
    expect(todos).toHaveLength(1);
    expect(todos[0]).toHaveTextContent('Test Todo 1');

    fireEvent.change(filterField, { target: { value: 'all' } });
    todos = listTodo.querySelectorAll('li');
    expect(todos).toHaveLength(2);
  });
});
