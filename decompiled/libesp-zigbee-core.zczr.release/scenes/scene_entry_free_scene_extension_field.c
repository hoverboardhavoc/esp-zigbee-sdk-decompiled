/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> scenes.o -> scene_entry_free_scene_extension_field
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void scene_entry_free_scene_extension_field(int param_1)

{
  int *piVar1;
  int *piVar2;
  
  if (param_1 != 0) {
    piVar1 = *(int **)(param_1 + 0x1c);
    if (*(int **)(param_1 + 0x1c) != (int *)0x0) {
      do {
        piVar2 = (int *)*piVar1;
        if (piVar1[2] != 0) {
          mm_free();
        }
        *(undefined1 *)((int)piVar1 + 6) = 0;
        mm_free(piVar1);
        piVar1 = piVar2;
      } while (piVar2 != (int *)0x0);
      *(undefined4 *)(param_1 + 0x1c) = 0;
    }
    return;
  }
  return;
}

