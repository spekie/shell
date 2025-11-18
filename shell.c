/*
 * Copyright (c) 2025 spekie
 *
 * Permission to use, copy, modify, and distribute this software for any
 * purpose with or without fee is hereby granted, provided that the above
 * copyright notice and this permission notice appear in all copies.
 *
 * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES
 * WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF
 * MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR
 * ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES
 * WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN
 * ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF
 * OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
 */

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAXCMD 1024

int main() {
	char cmd[MAXCMD];
	char *args[MAXCMD];
	char *tok;
	pid_t pid;
	int i;

	for (;;) {
		printf(">$ ");
		if (!fgets(cmd, sizeof(cmd), stdin))
			break;

		cmd[strcspn(cmd, "\n")] = 0;

		if (!*cmd)
			continue;

		if (!strcmp(cmd, "exit"))
			break;

		pid = fork();
		if (pid < 0) {
			_exit(1);
		}
			if (pid == 0) {
			tok = strtok(cmd, " \t");
			i = 0;
			while (tok && i < MAXCMD - 1) {
				args[i] = tok;
				i++;
				tok = strtok(NULL, " \t");
			}
			args[i] = NULL;

			execvp(args[0], args);
			printf("\n");
			_exit(1);
		}
		wait(NULL);
	}
	return 0;
}
