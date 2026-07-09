/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> nwk_formation.o -> nwk_formation_ed_scan_callback
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void nwk_formation_ed_scan_callback(void *param_1)

{
  char cVar1;
  int iVar2;
  undefined2 *puVar3;
  int iVar4;
  undefined1 uStack_20;
  undefined1 uStack_1f;
  undefined1 auStack_1e [2];
  undefined4 uStack_1c;
  code *pcStack_18;
  
  iVar2 = core_globals_get();
  if (param_1 != (void *)0x0) {
    cVar1 = *(char *)((int)param_1 + 3);
    if (cVar1 < -0x3b) {
      *(uint *)(iVar2 + 0xac8) =
           1 << (*(byte *)((int)param_1 + 2) & 0x1f) & 0x7ffffffU |
           *(uint *)(iVar2 + 0xac8) & 0x7ffffff | (uint)*(byte *)((int)param_1 + 1) << 0x1b;
    }
    if (cVar1 < *(char *)(iVar2 + 0xad0)) {
      memcpy((void *)(iVar2 + 0xacd),param_1,4);
    }
    return;
  }
  if (((*(uint *)(iVar2 + 0xac8) & 0x7ffffff) == 0) && (*(byte *)(iVar2 + 0xace) != 0xff)) {
    *(uint *)(iVar2 + 0xac8) =
         1 << (*(byte *)(iVar2 + 0xacf) & 0x1f) & 0x7ffffffU |
         (uint)*(byte *)(iVar2 + 0xace) << 0x1b;
  }
  if ((*(uint *)(iVar2 + 0xac8) & 0x7ffffff) != 0) {
    puVar3 = (undefined2 *)nwk_disc_table_lite_get_slot(0);
    *puVar3 = 0xffff;
    *(undefined1 *)(puVar3 + 1) = 0xff;
    puVar3 = (undefined2 *)nwk_disc_table_lite_get_slot(1);
    *puVar3 = 0xffff;
    *(undefined1 *)(puVar3 + 1) = 0xff;
    iVar4 = core_globals_get();
    *(undefined1 *)(iVar4 + 0xba4) = 1;
    memset(auStack_1e,0,0xe);
    uStack_1f = *(undefined1 *)(iVar2 + 0xacc);
    uStack_1c = *(undefined4 *)(iVar2 + 0xac8);
    uStack_20 = 1;
    pcStack_18 = nwk_formation_active_scan_callback;
    iVar2 = nwk_mm_scan_request(0,&uStack_20);
    if (iVar2 == 0) {
      return;
    }
  }
  iVar2 = core_globals_get();
  *(undefined1 *)(iVar2 + 0xac0) = 0;
  nwk_network_formation_confirm(0xc4);
  return;
}

