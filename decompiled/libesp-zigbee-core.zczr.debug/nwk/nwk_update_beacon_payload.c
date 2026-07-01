/*
 * Last changed at upstream commit 9bb2fbe73d004aaf258c1dadba7f98d929fbdfc8
 * https://github.com/espressif/esp-zigbee-sdk/commit/9bb2fbe73d004aaf258c1dadba7f98d929fbdfc8
 * Upstream date: 2026-07-01 11:36:50 +0800
 * Upstream subject: change: update esp-zigbee-lib (9401bce7)
 * Source: libesp-zigbee-core.zczr.debug -> nwk.o -> nwk_update_beacon_payload
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void nwk_update_beacon_payload(void)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  undefined3 uVar3;
  undefined4 uVar4;
  byte bVar5;
  int iVar6;
  int iVar7;
  uint uVar8;
  uint uVar9;
  ezb_extpanid_t *peVar10;
  byte bVar11;
  
  iVar6 = core_globals_get();
  *(undefined1 *)(iVar6 + 0xa3f) = 0;
  *(byte *)(iVar6 + 0xa40) = *(byte *)(iVar6 + 0xa40) & 0xf0 | 2;
  *(undefined1 *)(iVar6 + 0xa40) = 0x22;
  iVar7 = core_globals_get();
  bVar11 = *(byte *)(iVar6 + 0xa41) & 0x87;
  bVar5 = (byte)((*(byte *)(iVar7 + 0xa3c) & 0xf) << 3);
  *(byte *)(iVar6 + 0xa41) = bVar11 | bVar5;
  *(byte *)(iVar6 + 0xa41) = bVar11 | bVar5 | 4;
  uVar8 = nwk_neighbor_table_get_ed_num();
  uVar9 = nwk_neighbor_table_get_ed_capacity();
  if (uVar8 < uVar9) {
    uVar8 = nwk_neighbor_table_get_ed_num();
    iVar7 = core_globals_get();
    if (uVar8 < *(byte *)(iVar7 + 0x9db)) {
      iVar7 = 1;
    }
    else {
      iVar7 = 0;
    }
  }
  else {
    iVar7 = 0;
  }
  *(byte *)(iVar6 + 0xa41) = *(byte *)(iVar6 + 0xa41) & 0x7f | (byte)(iVar7 << 7);
  peVar10 = nwk_get_extended_panid();
  uVar2 = *(undefined4 *)&peVar10->field_0;
  puVar1 = (undefined4 *)((int)&peVar10->field_0 + 4);
  uVar3 = *(undefined3 *)puVar1;
  uVar4 = *puVar1;
  *(char *)(iVar6 + 0xa42) = (char)*(undefined3 *)&peVar10->field_0;
  *(char *)(iVar6 + 0xa43) = (char)((uint)uVar2 >> 8);
  *(char *)(iVar6 + 0xa44) = (char)((uint)uVar2 >> 0x10);
  *(char *)(iVar6 + 0xa45) = (char)((uint)uVar2 >> 0x18);
  *(char *)(iVar6 + 0xa46) = (char)uVar3;
  *(char *)(iVar6 + 0xa47) = (char)((uint)uVar4 >> 8);
  *(char *)(iVar6 + 0xa48) = (char)((uint)uVar4 >> 0x10);
  *(char *)(iVar6 + 0xa49) = (char)((uint)uVar4 >> 0x18);
  *(undefined1 *)(iVar6 + 0xa4a) = 0xff;
  *(undefined1 *)(iVar6 + 0xa4b) = 0xff;
  *(undefined1 *)(iVar6 + 0xa4c) = 0xff;
  iVar7 = core_globals_get();
  *(undefined1 *)(iVar6 + 0xa4d) = *(undefined1 *)(iVar7 + 0x9df);
  return;
}

