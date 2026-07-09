/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> nwk_formation.o -> nwk_formation_ed_scan_callback
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void nwk_formation_ed_scan_callback(undefined1 *param_1)

{
  byte bVar1;
  undefined1 uVar2;
  undefined1 uVar3;
  undefined1 uVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  undefined4 local_20;
  undefined4 uStack_1c;
  code *pcStack_18;
  undefined4 uStack_14;
  
  iVar5 = core_globals_get();
  if (param_1 == (undefined1 *)0x0) {
    if (((*(uint *)(iVar5 + 0xac8) & 0x7ffffff) == 0) && (*(byte *)(iVar5 + 0xace) != 0xff)) {
      uVar6 = (uint)*(byte *)(iVar5 + 0xace) << 0x1b;
      uVar7 = *(uint *)(iVar5 + 0xac8) & 0x7ffffff;
      *(uint *)(iVar5 + 0xac8) = uVar7 | uVar6;
      *(uint *)(iVar5 + 0xac8) = uVar6 | uVar7 | 1 << (*(byte *)(iVar5 + 0xacf) & 0x1f) & 0x7ffffffU
      ;
    }
    if ((*(uint *)(iVar5 + 0xac8) & 0x7ffffff) != 0) {
      nwk_disc_table_lite_init();
      uStack_14 = 0;
      local_20 = (uint)CONCAT11(*(undefined1 *)(iVar5 + 0xacc),1);
      uStack_1c = *(undefined4 *)(iVar5 + 0xac8);
      pcStack_18 = nwk_formation_active_scan_callback;
      iVar5 = nwk_mm_scan_request(0,&local_20);
      if (iVar5 == 0) {
        return;
      }
    }
    iVar5 = core_globals_get();
    *(undefined1 *)(iVar5 + 0xac0) = 0;
    nwk_network_formation_confirm(0xc4);
  }
  else {
    if ((char)param_1[3] < -0x3b) {
      bVar1 = param_1[1];
      uVar6 = *(uint *)(iVar5 + 0xac8) & 0x7ffffff;
      *(uint *)(iVar5 + 0xac8) = uVar6 | (uint)bVar1 << 0x1b;
      *(uint *)(iVar5 + 0xac8) =
           (uint)bVar1 << 0x1b | uVar6 | 1 << ((byte)param_1[2] & 0x1f) & 0x7ffffffU;
    }
    if ((char)param_1[3] < *(char *)(iVar5 + 0xad0)) {
      uVar2 = param_1[1];
      uVar3 = param_1[2];
      uVar4 = param_1[3];
      *(undefined1 *)(iVar5 + 0xacd) = *param_1;
      *(undefined1 *)(iVar5 + 0xace) = uVar2;
      *(undefined1 *)(iVar5 + 0xacf) = uVar3;
      *(undefined1 *)(iVar5 + 0xad0) = uVar4;
    }
  }
  return;
}

