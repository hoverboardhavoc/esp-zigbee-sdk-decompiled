/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> groups.o -> groups_append_group_name
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

ezb_err_t groups_append_group_name(zcl_packet_payload_t *payload,uint16_t length,void *group_name)

{
  ezb_err_t eVar1;
  undefined1 auStack_11 [13];
  
  auStack_11[0] = 0;
  eVar1 = zmsg_append_bytes(1,auStack_11);
  return eVar1;
}

