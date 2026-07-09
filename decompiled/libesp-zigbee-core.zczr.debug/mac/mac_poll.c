/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> mac.o -> mac_poll
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 mac_poll(int param_1,char *param_2)

{
  undefined2 uVar1;
  undefined2 uVar2;
  undefined2 uVar3;
  int iVar4;
  undefined4 uVar5;
  
  iVar4 = mac_is_enabled();
  if (iVar4 == 0) {
    uVar5 = 3;
  }
  else if (*(char *)(param_1 + 0x2d) == '\x02') {
    uVar5 = 3;
  }
  else {
    iVar4 = mac_is_op_busy(param_1,5);
    if (iVar4 == 0) {
      if ((param_2 != (char *)0x0) && (iVar4 = mac_is_associated(param_1), iVar4 == 0)) {
        if (*param_2 == '\x02') {
          *(undefined2 *)(param_1 + 0xe) = *(undefined2 *)(param_2 + 2);
        }
        else {
          if (*param_2 != '\x03') {
            return 2;
          }
          uVar1 = *(undefined2 *)(param_2 + 4);
          uVar2 = *(undefined2 *)(param_2 + 6);
          uVar3 = *(undefined2 *)(param_2 + 8);
          *(undefined2 *)(param_1 + 0x10) = *(undefined2 *)(param_2 + 2);
          *(undefined2 *)(param_1 + 0x12) = uVar1;
          *(undefined2 *)(param_1 + 0x14) = uVar2;
          *(undefined2 *)(param_1 + 0x16) = uVar3;
        }
        mac_set_panid(param_1,*(undefined2 *)(param_2 + 10));
      }
      mac_start_op(param_1,5);
      uVar5 = 0;
    }
    else {
      uVar5 = 0;
    }
  }
  return uVar5;
}

