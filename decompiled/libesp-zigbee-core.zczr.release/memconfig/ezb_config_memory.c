/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> memconfig.o -> ezb_config_memory
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 ezb_config_memory(ushort *param_1)

{
  ushort uVar1;
  ushort uVar2;
  ushort uVar3;
  int iVar4;
  
  iVar4 = core_globals_inited();
  if (iVar4 == 0) {
    return 3;
  }
  if (param_1 == (ushort *)0x0) {
    return 2;
  }
  if ((*param_1 & 0xffbf) != 0) {
    mempool_resize();
  }
  if ((param_1[1] & 0xffbf) != 0) {
    nwk_address_deinit();
    nwk_address_init(param_1[1]);
  }
  if ((param_1[2] & 0xffbf) != 0) {
    nwk_neighbor_table_deinit();
    nwk_neighbor_table_init(param_1[2]);
    nwk_btt_deinit();
    nwk_btt_init();
  }
  if ((param_1[3] & 0xffbf) != 0) {
    nwk_route_table_deinit();
    nwk_route_table_init(param_1[3]);
  }
  if ((param_1[4] & 0xffdf) != 0) {
    nwk_route_disc_table_deinit();
    nwk_route_disc_table_init(param_1[4]);
  }
  if ((param_1[5] & 0xffbf) != 0) {
    nwk_route_record_table_deinit();
    nwk_route_record_table_init(param_1[5]);
  }
  if ((param_1[6] & 0xffbf) != 0) {
    aps_secur_key_pair_set_deinit();
    aps_secur_key_pair_set_init(param_1[6]);
  }
  uVar3 = param_1[7];
  if (uVar3 == 0) {
    uVar3 = 0x10;
  }
  uVar2 = param_1[8];
  if (uVar2 == 0) {
    uVar2 = 0x10;
    uVar1 = uVar3;
  }
  else {
    uVar1 = uVar2;
    if (uVar3 != 0x10) goto _L0;
  }
  if (uVar1 == 0x10) {
    return 0;
  }
_L0:
  aps_bind_table_deinit();
  aps_bind_table_init(uVar3 & 0xff,uVar2 & 0xff);
  return 0;
}

