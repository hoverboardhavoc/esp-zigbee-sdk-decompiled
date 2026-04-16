/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> alarms.o -> ds_alarm_log_delete
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

ezb_err_t ds_alarm_log_delete(ds_alarm_log_iterator_t *itor)

{
  ezb_err_t eVar1;
  
  if (itor->is_done == false) {
    eVar1 = ds_internal_remove_entry(0xc,itor->index,itor);
  }
  else {
    eVar1 = 3;
  }
  return eVar1;
}

