/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> zcl_packet.o -> zcl_packet_max_available_space
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

uint16_t zcl_packet_max_available_space(uint16_t cluster_id,_Bool is_secured,_Bool is_manuf)

{
  short sVar1;
  undefined2 in_register_0000202a;
  undefined3 in_register_0000202d;
  undefined3 in_register_00002031;
  
  zcl_cluster_fragment_is_supported(CONCAT22(in_register_0000202a,cluster_id));
  sVar1 = aps_get_max_asdu(CONCAT31(in_register_0000202d,is_secured),0);
  return sVar1 - ((-(ushort)(CONCAT31(in_register_00002031,is_manuf) == 0) & 0xfffe) + 5);
}

