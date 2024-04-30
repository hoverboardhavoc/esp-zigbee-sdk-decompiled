/*
 * Last changed at upstream commit f681c92f221e08b8a4008d1df363fb1f9960ae64
 * https://github.com/espressif/esp-zigbee-sdk/commit/f681c92f221e08b8a4008d1df363fb1f9960ae64
 * Upstream date: 2024-04-30 13:18:04 +0800
 * Upstream subject: esp-zigbee-sdk: release/v1.3.1(ce7ce7c1)
 * Source: libesp_zb_api_zczr.debug -> esp_zigbee_zcl_commissioning.o -> esp_zb_zcl_commissioning_init_server
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void esp_zb_zcl_commissioning_init_server(void)

{
  int iVar1;
  
  iVar1 = get_endpoint_by_cluster(0x15,1);
  if (iVar1 != 0) {
    zb_af_get_endpoint_desc();
    get_cluster_desc(0x15,1);
    esp_zcl_commissioning_link_attr_with_ctx();
    zb_zcl_add_cluster_handlers
              (0x15,1,0,esp_zcl_comm_write_attr_hook,
               esp_zcl_process_commissioning_srv_specific_commands);
    return;
  }
  zb_assert("/builds/thread_zigbee/esp-zboss/components/esp_zb_sdk/src/zcl/esp_zigbee_zcl_commissioning.c"
            ,0x309);
  zb_zcl_add_cluster_handlers(0x15,2,0,0,esp_zcl_process_commissioning_cli_specific_commands);
  return;
}

