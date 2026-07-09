/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> mac.o -> mac_convert_beacon_to_beacon_notify_ind
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 mac_convert_beacon_to_beacon_notify_ind(int *param_1,void *param_2)

{
  undefined2 uVar1;
  undefined2 uVar2;
  short sVar3;
  int iVar4;
  int iVar5;
  undefined4 uVar6;
  undefined2 *puVar7;
  
  memset(param_2,0,0x1c);
  if (param_1 == (int *)0x0) {
    uVar6 = 2;
  }
  else {
    iVar5 = mac_is_valid_beacon_frame(param_1);
    if (iVar5 == 0) {
      uVar6 = 0x10;
    }
    else {
      puVar7 = (undefined2 *)param_1[9];
      *(bool *)((int)param_2 + 2) = (*(ushort *)(param_1 + 7) & 0x3000) == 0x2000;
      if (*(char *)((int)param_1 + 0xe) == '\0') {
        uVar6 = 0x10;
      }
      else {
        iVar5 = param_1[4];
        uVar1 = *(undefined2 *)((int)param_1 + 0x12);
        iVar4 = param_1[5];
        uVar2 = *(undefined2 *)((int)param_1 + 0x16);
        *(undefined2 *)((int)param_2 + 4) = *(undefined2 *)((int)param_1 + 0xe);
        *(short *)((int)param_2 + 6) = (short)iVar5;
        *(undefined2 *)((int)param_2 + 8) = uVar1;
        *(short *)((int)param_2 + 10) = (short)iVar4;
        *(undefined2 *)((int)param_2 + 0xc) = uVar2;
        sVar3 = *(short *)((int)param_1 + 0x1a);
        *(short *)((int)param_2 + 0xe) = sVar3;
        if (sVar3 == -1) {
          *(short *)((int)param_2 + 0xe) = (short)param_1[6];
        }
        *(undefined1 *)((int)param_2 + 0x11) = *(undefined1 *)(*param_1 + 5);
        *(undefined1 *)((int)param_2 + 0x14) = *(undefined1 *)(*param_1 + 0x11);
        *(undefined1 *)((int)param_2 + 0x15) = *(undefined1 *)(*param_1 + 0x10);
        *(undefined2 *)((int)param_2 + 0x12) = *puVar7;
        *(undefined1 *)((int)param_2 + 1) = *(undefined1 *)((int)param_1 + 0x1e);
        *(undefined2 **)((int)param_2 + 0x18) = puVar7 + 2;
        *(char *)((int)param_2 + 0x16) = (char)param_1[8] + -4;
        uVar6 = 0;
      }
    }
  }
  return uVar6;
}

