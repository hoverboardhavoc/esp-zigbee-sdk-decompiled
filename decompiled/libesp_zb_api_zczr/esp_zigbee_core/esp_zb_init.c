/*
 * Last changed at upstream commit 3128a1de3a8a176dac99e12775a60287e9d10fd7
 * https://github.com/espressif/esp-zigbee-sdk/commit/3128a1de3a8a176dac99e12775a60287e9d10fd7
 * Upstream date: 2024-04-01 17:59:07 +0800
 * Upstream subject: esp-zigbee-sdk: release/v1.2.2(4a0e02cc)
 * Source: libesp_zb_api_zczr -> esp_zigbee_core.o -> esp_zb_init
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void esp_zb_init(char *param_1)

{
  char cVar1;
  undefined4 uVar2;
  uint uVar3;
  undefined4 *puVar4;
  
  zb_init();
  zb_nvram_register_app1_read_cb(zb_nvram_app1_read_cb);
  zb_nvram_register_app1_write_cb(zb_nvram_app1_write_cb,0x10000);
  puVar4 = (undefined4 *)&esp_zb_zcl_scenes_table;
  do {
    *(undefined2 *)((int)puVar4 + 2) = 0xffff;
    puVar4 = puVar4 + 3;
  } while (puVar4 != &zcl_cli_resp_user_cb);
  zb_set_installcode_policy(param_1[4]);
  cVar1 = *param_1;
  if (cVar1 == '\x01') {
    zb_set_network_router_role(0x7fff800);
  }
  else {
    if (cVar1 == '\x02') {
      zb_set_network_ed_role(0x7fff800);
      zb_set_ed_timeout(param_1[8]);
      uVar3 = *(uint *)(param_1 + 0xc) * 1000;
      __udivdi3((uint)(uVar3 + 0x3bff < uVar3) +
                (int)((ulonglong)*(uint *)(param_1 + 0xc) * 1000 >> 0x20),0x3c00,0);
      zb_set_keepalive_timeout();
      if (*(int *)(param_1 + 0xc) != 0) {
        esp_zb_set_default_long_poll_interval();
      }
      zb_set_nvram_erase_at_start(0);
      return;
    }
    if (cVar1 != '\0') {
      uVar2 = esp_log_timestamp();
      esp_log_write(1,"ESP_ZIGBEE_CORE",&_L0,uVar2,"ESP_ZIGBEE_CORE");
      return;
    }
    zb_set_network_coordinator_role(0x7fff800);
  }
  zb_set_max_children(param_1[8]);
  zb_set_nvram_erase_at_start(0);
  return;
}

