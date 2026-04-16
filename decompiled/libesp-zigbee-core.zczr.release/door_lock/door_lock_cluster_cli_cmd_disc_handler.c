/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> door_lock.o -> door_lock_cluster_cli_cmd_disc_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

uint8_t door_lock_cluster_cli_cmd_disc_handler(_Bool is_recv,uint8_t **list)

{
  undefined3 in_register_00002029;
  uint8_t *puVar1;
  
  if (CONCAT31(in_register_00002029,is_recv) == 0) {
    puVar1 = (uint8_t *)&recv_cmd_list_1;
  }
  else {
    puVar1 = (uint8_t *)&send_cmd_list_0;
  }
  *list = puVar1;
  return '\x02';
}

