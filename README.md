# This is repo for udemy cpp tasks and exercies
# v 0.01

# vs_code launch.json contents for lld debug

```bash
{
    // Use IntelliSense to learn about possible attributes.
    // Hover to view descriptions of existing attributes.
    // For more information, visit: https://go.microsoft.com/fwlink/?linkid=830387
    "version": "0.2.0",
    "configurations": [
        {
            "type": "lldb",
            "request": "launch",
            "name": "Launch",
            "program": "${workspaceFolder}/build/udemy_1_initial",
            "args": [],
            "cwd": "${workspaceFolder}"
        }
    ]
}
```