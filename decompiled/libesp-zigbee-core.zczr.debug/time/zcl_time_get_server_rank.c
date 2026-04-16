/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> time.o -> zcl_time_get_server_rank
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

ezb_zcl_time_server_rank_t zcl_time_get_server_rank(uint8_t time_status,uint16_t short_address)

{
  undefined2 in_register_0000202e;
  _Bool has_master;
  
  if (CONCAT22(in_register_0000202e,short_address) == 0) {
    if ((time_status & 8) != 0) {
      if ((time_status & 1) != 0) {
        return EZB_ZCL_TIME_SERVER_RANK_COORDINATOR_SUPERSEDING_MASTER;
      }
      goto _L0;
    }
  }
  else {
_L0:
    if ((time_status & 8) == 0) goto _L0;
    if ((time_status & 1) != 0) {
      return EZB_ZCL_TIME_SERVER_RANK_SUPERSEDING_MASTER;
    }
  }
  if ((time_status & 8) != 0) {
    return EZB_ZCL_TIME_SERVER_RANK_SUPERSEDING;
  }
_L0:
  if ((time_status & 1) != 0) {
    return EZB_ZCL_TIME_SERVER_RANK_MASTER;
  }
  if ((time_status & 2) != 0) {
    return EZB_ZCL_TIME_SERVER_RANK_SYNCHRONIZED;
  }
  return EZB_ZCL_TIME_SERVER_RANK_UNSYNCHRONIZED;
}

