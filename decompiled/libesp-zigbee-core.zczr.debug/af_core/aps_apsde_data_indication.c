/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> af_core.o -> aps_apsde_data_indication
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void aps_apsde_data_indication(aps_apsde_data_ind_t *ind)

{
  int iVar1;
  undefined4 uVar2;
  uint32_t delay_ms;
  
  if ((ind->addr_info).grp_addr == 0) {
    af_data_indication_deliver_handler(ind);
  }
  else {
    uVar2 = aps_group_table_find();
    iVar1 = 0xff;
    while (iVar1 = aps_group_next_endpoint(uVar2,iVar1 + 1U & 0xff), iVar1 != 0xff) {
      delay_ms = random_add_jitter(0,10);
      af_data_indication_deliver_ep(ind,(uint8_t)iVar1,delay_ms);
    }
  }
  return;
}

