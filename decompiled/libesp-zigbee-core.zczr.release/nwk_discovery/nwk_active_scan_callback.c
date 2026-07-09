/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> nwk_discovery.o -> nwk_active_scan_callback
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void nwk_active_scan_callback(byte *param_1)

{
  byte bVar1;
  char *pcVar2;
  undefined1 uVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  int iStack_2c;
  int iStack_28;
  short asStack_24 [4];
  undefined4 uStack_1c;
  undefined4 uStack_18;
  undefined4 uStack_14;
  
  if (param_1 == (byte *)0x0) {
    iVar4 = core_globals_get();
    *(undefined1 *)(iVar4 + 0xac0) = 0;
    nwk_network_discovery_confirm(0);
    return;
  }
  if (((((param_1[2] == 0) && (0xe < param_1[0x16])) &&
       (pcVar2 = *(char **)(param_1 + 0x18), *pcVar2 == '\0')) &&
      ((pcVar2[1] == '\"' &&
       ((iVar4 = core_globals_get(), *(char *)(iVar4 + 0xac8) == '\0' ||
        (*(short *)(param_1 + 0x12) < 0)))))) &&
     ((iVar4 = core_globals_get(), *(char *)(iVar4 + 0xac9) == '\0' || (pcVar2[2] < '\0')))) {
    iVar4 = 0x1000;
    iStack_2c = *(int *)(pcVar2 + 3);
    iStack_28 = *(int *)(pcVar2 + 7);
    iVar5 = core_globals_get();
    if (*(int *)(iVar5 + 0x9ef) != 0 || *(int *)(iVar5 + 0x9f3) != 0) goto _L0;
    while (uStack_1c = nwk_address_add_panid_mapping(*(undefined2 *)(param_1 + 0xe),&iStack_2c),
          uStack_1c == 0xff) {
      iVar4 = nwk_disc_table_find_weakest_pan(param_1[0x14]);
      if (iVar4 == 0xff) {
        return;
      }
      nwk_disc_table_remove_pan();
      uStack_1c = nwk_address_add_panid_mapping(*(undefined2 *)(param_1 + 0xe),&iStack_2c);
      if (uStack_1c != 0xff) break;
      __assert_func(0,0,0,0);
      iVar4 = 0xff;
_L0:
      iVar5 = core_globals_get();
      if (*(int *)(iVar5 + iVar4 + -0x611) != iStack_2c) {
        return;
      }
      if (*(int *)(iVar5 + iVar4 + -0x60d) != iStack_28) {
        return;
      }
    }
    bVar1 = param_1[4];
    uStack_1c = uStack_1c & 0xff;
    uStack_18 = 0;
    uStack_14 = 0;
    memcpy(asStack_24,param_1 + 6,8);
    uStack_14 = CONCAT13(*param_1 & 0x1f | (bVar1 == 2) << 5 | (byte)(uStack_14 >> 0x18) & 0xc0,
                         (undefined3)uStack_14);
    uVar3 = nwk_calculate_lqa_raw(param_1[0x14],(int)(char)param_1[0x15]);
    uVar6 = uStack_1c;
    uStack_1c._3_1_ = SUB41(uVar6,3);
    uStack_1c._0_3_ = CONCAT12(pcVar2[0xe],CONCAT11(uVar3,(undefined1)uStack_1c));
    uVar7 = (param_1[0x10] & 0x1f) << 7 | param_1[0x11] & 0x7f | ((byte)pcVar2[2] >> 2 & 1) << 0xe |
            (uint)((byte)pcVar2[2] >> 7) << 0xf | ((byte)pcVar2[1] & 3) << 0x10 |
            (uint)(*(ushort *)(param_1 + 0x12) >> 0xf) << 0x1e | uStack_14 & 0xbffc3000;
    uVar6 = 3;
    if ((int)(uVar7 << 2) < 0) {
      uVar6 = (uint)(asStack_24[0] != 0);
    }
    uStack_14._3_1_ = (undefined1)(uVar7 >> 0x18);
    uStack_14._0_3_ =
         CONCAT12((byte)(((byte)pcVar2[2] & 0x78) << 1) | (byte)(uVar6 << 2) |
                  (byte)((byte)pcVar2[1] & 3),(short)uVar7);
    nwk_disc_table_add_parent(asStack_24);
  }
  return;
}

