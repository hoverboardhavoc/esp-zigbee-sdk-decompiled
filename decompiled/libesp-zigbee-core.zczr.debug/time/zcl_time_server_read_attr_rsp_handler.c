/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> time.o -> zcl_time_server_read_attr_rsp_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int zcl_time_server_read_attr_rsp_handler(int param_1)

{
  ushort uVar1;
  uint *puVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  
  if (param_1 == 0) {
    iVar4 = 0;
  }
  else if (*(int *)(param_1 + 0xc) == 0) {
    iVar4 = 0;
  }
  else {
    iVar3 = time_server_get_time_ctx(*(undefined1 *)(*(int *)(param_1 + 8) + 0x15));
    if ((iVar3 == 0) || (iVar4 = milli_timer_is_running(iVar3 + 0xc), iVar4 == 0)) {
      iVar4 = 0;
    }
    else {
      uVar1 = *(ushort *)(*(int *)(param_1 + 8) + 2);
      uVar5 = 0;
      iVar6 = 0;
      for (puVar2 = *(uint **)(param_1 + 0xc); puVar2 != (uint *)0x0; puVar2 = (uint *)puVar2[2]) {
        if (((*puVar2 & 0xffffff) == 0) && ((int *)puVar2[1] != (int *)0x0)) {
          iVar6 = *(int *)puVar2[1];
        }
        else if (((*puVar2 & 0xffffff) == 1) && ((undefined1 *)puVar2[1] != (undefined1 *)0x0)) {
          uVar5 = zcl_time_get_server_rank(*(undefined1 *)puVar2[1],uVar1);
        }
      }
      if ((iVar6 != -1) &&
         ((*(byte *)(iVar3 + 0x24) < uVar5 ||
          ((*(byte *)(iVar3 + 0x24) == uVar5 && (uVar1 < *(ushort *)(iVar3 + 0x1c))))))) {
        *(char *)(iVar3 + 0x24) = (char)uVar5;
        *(ushort *)(iVar3 + 0x1c) = uVar1;
        if (*(int *)(iVar3 + 0x20) != iVar6) {
          *(int *)(iVar3 + 0x20) = iVar6;
          (**(code **)(iVar3 + 4))(iVar6,*(code **)(iVar3 + 4));
        }
      }
    }
  }
  return iVar4;
}

