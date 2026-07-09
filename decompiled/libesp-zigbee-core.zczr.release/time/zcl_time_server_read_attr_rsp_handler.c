/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> time.o -> zcl_time_server_read_attr_rsp_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int zcl_time_server_read_attr_rsp_handler(int param_1)

{
  byte bVar1;
  ushort uVar2;
  int iVar3;
  int iVar4;
  uint *puVar5;
  byte bVar6;
  int iVar7;
  
  if ((((param_1 == 0) || (*(int *)(param_1 + 0xc) == 0)) ||
      (iVar3 = time_server_get_time_ctx(*(undefined1 *)(*(int *)(param_1 + 8) + 0x15)), iVar3 == 0))
     || (iVar7 = milli_timer_is_running(iVar3 + 0xc), iVar7 == 0)) {
    iVar7 = 0;
  }
  else {
    uVar2 = *(ushort *)(*(int *)(param_1 + 8) + 2);
    iVar4 = 0;
    bVar6 = 0;
    for (puVar5 = *(uint **)(param_1 + 0xc); puVar5 != (uint *)0x0; puVar5 = (uint *)puVar5[2]) {
      if ((*puVar5 & 0xffffff) == 0) {
        if ((int *)puVar5[1] != (int *)0x0) {
          iVar4 = *(int *)puVar5[1];
        }
      }
      else if (((*puVar5 & 0xffffff) == 1) && ((byte *)puVar5[1] != (byte *)0x0)) {
        bVar1 = *(byte *)puVar5[1];
        if (uVar2 == 0) {
          if ((bVar1 & 8) == 0) {
_L0:
            bVar6 = 2;
            if ((bVar1 & 1) == 0) {
              bVar6 = bVar1 >> 1 & 1;
            }
          }
          else {
            bVar6 = 5;
            if ((bVar1 & 1) == 0) goto _L0;
          }
        }
        else {
          if ((bVar1 & 8) == 0) goto _L0;
_L0:
          bVar6 = (bVar1 & 1) + 3;
        }
      }
    }
    if ((iVar4 != -1) &&
       ((*(byte *)(iVar3 + 0x24) < bVar6 ||
        ((*(byte *)(iVar3 + 0x24) == bVar6 && (uVar2 < *(ushort *)(iVar3 + 0x1c))))))) {
      *(byte *)(iVar3 + 0x24) = bVar6;
      *(ushort *)(iVar3 + 0x1c) = uVar2;
      if (*(int *)(iVar3 + 0x20) != iVar4) {
        *(int *)(iVar3 + 0x20) = iVar4;
        (**(code **)(iVar3 + 4))(*(code **)(iVar3 + 4));
      }
    }
  }
  return iVar7;
}

