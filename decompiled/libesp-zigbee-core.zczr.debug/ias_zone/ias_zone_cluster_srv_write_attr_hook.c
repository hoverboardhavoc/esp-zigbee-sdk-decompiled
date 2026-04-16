/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> ias_zone.o -> ias_zone_cluster_srv_write_attr_hook
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void ias_zone_cluster_srv_write_attr_hook
               (uint8_t ep_id,uint16_t attr_id,void *new_value,uint16_t manuf_code)

{
  undefined2 in_register_0000202e;
  char *pcVar1;
  
  if (new_value == (void *)0x0) {
    pcVar1 = "ias_zone_cluster_srv_write_attr_hook";
    ep_id = __assert_func("//build/esp-zigbee/src/core/api/zcl/cluster/ias_zone.c",0x1fd,
                          "ias_zone_cluster_srv_write_attr_hook",0x10eb0);
    new_value = pcVar1;
  }
  else if (CONCAT22(in_register_0000202e,attr_id) != 2) {
    return;
  }
  ias_zone_zone_status_change_handler(ep_id,new_value);
  return;
}

