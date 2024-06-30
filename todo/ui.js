export const ui = `
    <div>
      <form type="action">
        <label for="input">
          <input type="text" id="todo-input" class="todo-input" name="todo" placeholder="Enter To Do" />
        </label>
        <button type="button" id="search-todo">
          <i class="fa-solid fa-magnifying-glass">+</i>
        </button>
        <button type="button" id="add-todo">Add</button>
        <select name="filter" id="filter-input">
          <option value="all">All</option>
          <option value="completed">Completed</option>
          <option value="active">Active</option>
        </select>
      </form>
    </div>
    <div class="">
      <ul class="todo-list" id="todo-list"></ul>
    </div>
`
