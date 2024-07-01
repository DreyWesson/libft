import { defineConfig } from 'vite'

export default defineConfig({
  server: {
    host: true, // Enable listening on all addresses
    port: 5173, // Ensure the port matches the one exposed in Dockerfile
  },
})
