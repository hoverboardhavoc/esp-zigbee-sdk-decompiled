/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> secur_ic.o -> secur_ic_get_stored_ic
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void secur_ic_get_stored_ic(ezb_extaddr_t *addr,ds_ic_info_iterator_t *itor)

{
  dataset_ic_info_t *ic;
  
  itor->index = 0;
  itor->is_done = false;
  while( true ) {
    ds_ic_info_itor_read(itor);
    if (itor->is_done != false) {
      return;
    }
    if ((*(int *)&addr->field_0 == *(int *)&(itor->data).device_address.field_0) &&
       (*(int *)((int)&addr->field_0 + 4) == *(int *)((int)&(itor->data).device_address.field_0 + 4)
       )) break;
    itor->index = itor->index + 1;
  }
  return;
}

