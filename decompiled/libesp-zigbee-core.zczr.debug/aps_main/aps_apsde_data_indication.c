/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> aps_main.o -> aps_apsde_data_indication
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void aps_apsde_data_indication(aps_apsde_data_ind_t *ind)

{
  log_write(3,"aps_main.c",">>>>>>>>>>>>>>>>>>>>");
  log_write(3,"aps_main.c","Rx APS Frame: 0x%04x:%d->0x%04x:%d profile(0x%04x) cluster(0x%04x)",
            (ind->addr_info).src_addr,(ind->addr_info).src_ep,(ind->addr_info).dst_addr,
            (ind->addr_info).dst_ep,(ind->addr_info).profile_id);
  log_write(3,"aps_main.c","<<<<<<<<<<<<<<<<<<<<");
  zmsg_dump(3,"aps_main.c",ind->asdu);
  zmsg_free(ind->asdu);
  return;
}

