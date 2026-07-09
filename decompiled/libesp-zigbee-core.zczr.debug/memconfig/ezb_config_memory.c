/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> memconfig.o -> ezb_config_memory
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 ezb_config_memory(short *param_1)

{
  ushort uVar1;
  ushort uVar2;
  int iVar3;
  undefined4 uVar4;
  
  iVar3 = core_globals_inited();
  if (iVar3 == 0) {
    uVar4 = 3;
  }
  else if (param_1 == (short *)0x0) {
    uVar4 = 2;
  }
  else {
    if ((*param_1 != 0) && (*param_1 != 0x40)) {
      mempool_resize();
    }
    if ((param_1[1] != 0) && (param_1[1] != 0x40)) {
      nwk_address_deinit();
      nwk_address_init(param_1[1]);
    }
    if ((param_1[2] != 0) && (param_1[2] != 0x40)) {
      nwk_neighbor_table_deinit();
      nwk_neighbor_table_init(param_1[2]);
      nwk_btt_deinit();
      nwk_btt_init();
    }
    if ((param_1[3] != 0) && (param_1[3] != 0x40)) {
      nwk_route_table_deinit();
      nwk_route_table_init(param_1[3]);
    }
    if ((param_1[4] != 0) && (param_1[4] != 0x20)) {
      nwk_route_disc_table_deinit();
      nwk_route_disc_table_init(param_1[4]);
    }
    if ((param_1[5] != 0) && (param_1[5] != 0x40)) {
      nwk_route_record_table_deinit();
      nwk_route_record_table_init(param_1[5]);
    }
    if ((param_1[6] != 0) && (param_1[6] != 0x40)) {
      aps_secur_key_pair_set_deinit();
      aps_secur_key_pair_set_init(param_1[6]);
    }
    uVar2 = param_1[7];
    if (uVar2 == 0) {
      uVar2 = 0x10;
    }
    uVar1 = param_1[8];
    if (uVar1 == 0) {
      uVar1 = 0x10;
    }
    if ((uVar2 == 0x10) && (uVar1 == 0x10)) {
      uVar4 = 0;
    }
    else {
      aps_bind_table_deinit();
      aps_bind_table_init(uVar2 & 0xff,uVar1 & 0xff);
      uVar4 = 0;
    }
  }
  return uVar4;
}

