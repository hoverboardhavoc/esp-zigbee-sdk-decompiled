/*
 * Last changed at upstream commit 9bb2fbe73d004aaf258c1dadba7f98d929fbdfc8
 * https://github.com/espressif/esp-zigbee-sdk/commit/9bb2fbe73d004aaf258c1dadba7f98d929fbdfc8
 * Upstream date: 2026-07-01 11:36:50 +0800
 * Upstream subject: change: update esp-zigbee-lib (9401bce7)
 * Source: libesp-zigbee-core.zczr.debug -> aps_secur.o -> aps_process_transmit_security
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

ezb_err_t aps_process_transmit_security(ezb_extaddr_t *dst_addr,zmsg_t *msg)

{
  aps_device_key_pair_t *key_pair;
  ezb_err_t eVar1;
  
  key_pair = aps_secur_get_key_pair_by_addr(dst_addr);
  eVar1 = aps_process_transmit_security_by_key_pair(key_pair,msg);
  return eVar1;
}

