/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> memconfig.o -> ezb_config_memory
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

ezb_err_t ezb_config_memory(ezb_mem_config_t *mem_cfg)

{
  ushort uVar1;
  ushort uVar2;
  ushort uVar3;
  int iVar4;
  
  iVar4 = core_globals_inited();
  if (iVar4 == 0) {
    return 3;
  }
  if (mem_cfg == (ezb_mem_config_t *)0x0) {
    return 2;
  }
  if ((mem_cfg->buffer_pool_size & 0xffbf) != 0) {
    mempool_resize();
  }
  if ((mem_cfg->address_table_size & 0xffbf) != 0) {
    nwk_address_deinit();
    nwk_address_init(mem_cfg->address_table_size);
  }
  if ((mem_cfg->neighbor_table_size & 0xffbf) != 0) {
    nwk_neighbor_table_deinit();
    nwk_neighbor_table_init(mem_cfg->neighbor_table_size);
  }
  if ((mem_cfg->route_table_size & 0xffbf) != 0) {
    nwk_route_table_deinit();
    nwk_route_table_init(mem_cfg->route_table_size);
  }
  if ((mem_cfg->route_discovery_table_size & 0xffdf) != 0) {
    nwk_route_disc_table_deinit();
    nwk_route_disc_table_init(mem_cfg->route_discovery_table_size);
  }
  if ((mem_cfg->route_record_table_size & 0xffbf) != 0) {
    nwk_route_record_table_deinit();
    nwk_route_record_table_init(mem_cfg->route_record_table_size);
  }
  if ((mem_cfg->aps_key_pair_set_size & 0xffbf) != 0) {
    aps_secur_key_pair_set_deinit();
    aps_secur_key_pair_set_init(mem_cfg->aps_key_pair_set_size);
  }
  uVar3 = mem_cfg->aps_bind_table_src_size;
  if (uVar3 == 0) {
    uVar3 = 0x10;
  }
  uVar2 = mem_cfg->aps_bind_table_dst_size;
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

