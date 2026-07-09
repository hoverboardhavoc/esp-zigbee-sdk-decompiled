/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> nwk_discovery.o -> nwk_handle_active_scan_result
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void nwk_handle_active_scan_result(byte *param_1)

{
  char *pcVar1;
  undefined1 uVar2;
  int iVar3;
  undefined4 uStack_2c;
  undefined4 uStack_28;
  undefined4 uStack_24;
  undefined4 uStack_20;
  uint uStack_1c;
  int iStack_18;
  int iStack_14;
  
  if (((((param_1[2] == 0) && (pcVar1 = *(char **)(param_1 + 0x18), 0xe < param_1[0x16])) &&
       (*pcVar1 == '\0')) &&
      ((pcVar1[1] == '\"' &&
       ((iVar3 = core_globals_get(), *(char *)(iVar3 + 0xac8) == '\0' ||
        (*(short *)(param_1 + 0x12) < 0)))))) &&
     ((iVar3 = core_globals_get(), *(char *)(iVar3 + 0xac9) == '\0' || (pcVar1[2] < '\0')))) {
    iStack_18 = *(int *)(pcVar1 + 3);
    iStack_14 = *(int *)(pcVar1 + 7);
    iVar3 = core_globals_get();
    if (*(int *)(iVar3 + 0x9ef) != 0 || *(int *)(iVar3 + 0x9f3) != 0) {
      iVar3 = core_globals_get();
      if (*(int *)(iVar3 + 0x9ef) != iStack_18) {
        return;
      }
      if (*(int *)(iVar3 + 0x9f3) != iStack_14) {
        return;
      }
    }
    uStack_24 = nwk_address_add_panid_mapping(*(undefined2 *)(param_1 + 0xe),&iStack_18);
    if (uStack_24 == 0xff) {
      iVar3 = nwk_disc_table_find_weakest_pan(param_1[0x14]);
      if (iVar3 == 0xff) {
        return;
      }
      nwk_disc_table_remove_pan();
      uStack_24 = nwk_address_add_panid_mapping(*(undefined2 *)(param_1 + 0xe),&iStack_18);
      if (uStack_24 == 0xff) {
        iVar3 = __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/nwk/nwk_discovery.c",0x6c,
                              "nwk_handle_active_scan_result","panid_ref != ((nwk_panid_ref_t)(-1))"
                             );
        if (iVar3 == 0) {
          iVar3 = core_globals_get();
          *(undefined1 *)(iVar3 + 0xac0) = 0;
          nwk_network_discovery_confirm(0);
        }
        else {
          nwk_handle_active_scan_result();
        }
        return;
      }
    }
    uStack_20 = 0;
    uStack_24 = uStack_24 & 0xff;
    uStack_2c = *(undefined4 *)(param_1 + 6);
    uStack_28 = *(undefined4 *)(param_1 + 10);
    uStack_1c = (uint)(param_1[4] == 2) << 0x1d | (*param_1 & 0x1f) << 0x18;
    uVar2 = nwk_calculate_lqa_raw(param_1[0x14],(int)(char)param_1[0x15]);
    uStack_24._0_2_ = CONCAT11(uVar2,(undefined1)uStack_24);
    uStack_1c = uStack_1c & 0xbffff000 | param_1[0x11] & 0x7f | (param_1[0x10] & 0x1f) << 7 |
                (uint)(*(ushort *)(param_1 + 0x12) >> 0xf) << 0x1e;
    convert_beacon_to_parent(&uStack_2c,pcVar1);
    nwk_disc_table_add_parent(&uStack_2c);
  }
  return;
}

