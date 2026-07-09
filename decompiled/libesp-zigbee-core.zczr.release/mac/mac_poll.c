/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> mac.o -> mac_poll
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 mac_poll(int param_1,char *param_2)

{
  undefined4 uVar1;
  
  if ((*(uint *)(param_1 + 0x9c) & 1) == 0) {
    return 3;
  }
  uVar1 = 3;
  if (*(char *)(param_1 + 0x2d) != '\x02') {
    if ((*(char *)(param_1 + 0x2e) != '\x05') && ((*(ushort *)(param_1 + 0x30) & 0x20) == 0)) {
      if ((param_2 != (char *)0x0) && (*(short *)(param_1 + 8) == -1)) {
        if (*param_2 == '\x02') {
          *(undefined2 *)(param_1 + 0xe) = *(undefined2 *)(param_2 + 2);
        }
        else {
          if (*param_2 != '\x03') {
            return 2;
          }
          memcpy((void *)(param_1 + 0x10),param_2 + 2,8);
        }
        mac_set_panid(param_1,*(undefined2 *)(param_2 + 10));
      }
      mac_start_op(param_1,5);
    }
    uVar1 = 0;
  }
  return uVar1;
}

