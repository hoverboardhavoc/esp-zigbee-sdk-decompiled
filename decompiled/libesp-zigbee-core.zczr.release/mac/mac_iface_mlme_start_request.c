/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> mac.o -> mac_iface_mlme_start_request
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 mac_iface_mlme_start_request(undefined4 *param_1,short *param_2)

{
  short sVar1;
  undefined1 *puVar2;
  undefined4 uVar3;
  int iVar4;
  undefined4 uVar5;
  
  puVar2 = (undefined1 *)*param_1;
  uVar3 = 3;
  if ((((*(uint *)(puVar2 + 0x9c) & 1) != 0) && (uVar3 = 2, param_2 != (short *)0x0)) &&
     (uVar3 = 0x1ec, *(short *)(puVar2 + 8) != -1)) {
    uVar3 = 0x1e8;
    if (*param_2 != -1) {
      iVar4 = mac_set_pan_channel(puVar2,*(undefined1 *)((int)param_2 + 3),(char)param_2[1]);
      if (iVar4 == 0) {
        if ((param_2[2] & 1U) == 0) {
          *(undefined2 *)(puVar2 + 0xe) = 0xffff;
          uVar3 = 0;
          uVar5 = 0;
        }
        else {
          *(undefined2 *)(puVar2 + 0xe) = *(undefined2 *)(puVar2 + 8);
          uVar3 = CONCAT13(puVar2[3],CONCAT12(puVar2[2],CONCAT11(puVar2[1],*puVar2)));
          uVar5 = CONCAT13(puVar2[7],CONCAT12(puVar2[6],CONCAT11(puVar2[5],puVar2[4])));
        }
        puVar2[0x10] = (char)uVar3;
        puVar2[0x11] = (char)((uint)uVar3 >> 8);
        puVar2[0x13] = (char)((uint)uVar3 >> 0x18);
        sVar1 = *param_2;
        puVar2[0x14] = (char)uVar5;
        puVar2[0x15] = (char)((uint)uVar5 >> 8);
        puVar2[0x12] = (char)((uint)uVar3 >> 0x10);
        puVar2[0x16] = (char)((uint)uVar5 >> 0x10);
        puVar2[0x17] = (char)((uint)uVar5 >> 0x18);
        mac_set_panid(puVar2,sVar1);
      }
      uVar3 = 0;
    }
  }
  return uVar3;
}

