/*
 * Last changed at upstream commit edae603135f5169e47a3eae722f314ece18018a0
 * https://github.com/espressif/esp-zigbee-sdk/commit/edae603135f5169e47a3eae722f314ece18018a0
 * Upstream date: 2022-09-28 15:45:52 +0800
 * Upstream subject: Components: Update sdk_lib for support more devices/cluster
 * Source: libesp_zb_api_zczr -> esp_zigbee_zcl_command.o -> esp_zb_zcl_custom_cluster_cmd_req
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void esp_zb_zcl_custom_cluster_cmd_req(int param_1)

{
  byte bVar1;
  undefined4 uVar2;
  undefined1 *puVar3;
  undefined4 uVar4;
  
  uVar2 = zb_buf_get_out_func();
  puVar3 = (undefined1 *)zb_zcl_start_command_header(1,0,*(undefined1 *)(param_1 + 0x18),0);
  bVar1 = *(byte *)(param_1 + 0x14);
  if (bVar1 == 0x28) {
    *puVar3 = **(undefined1 **)(param_1 + 0x10);
    puVar3 = puVar3 + 1;
    goto _L0;
  }
  if (bVar1 < 0x29) {
    if (bVar1 == 0x21) {
      puVar3 = (undefined1 *)zb_put_next_htole16(**(undefined2 **)(param_1 + 0x10));
      goto _L0;
    }
    if (bVar1 == 0x23) {
      puVar3 = (undefined1 *)zb_put_next_htole32(**(undefined4 **)(param_1 + 0x10));
      goto _L0;
    }
    if (bVar1 == 0x20) {
      *puVar3 = **(undefined1 **)(param_1 + 0x10);
      puVar3 = puVar3 + 1;
      goto _L0;
    }
  }
  else {
    if (bVar1 == 0x2b) {
      puVar3 = (undefined1 *)zb_put_next_htole32(**(undefined4 **)(param_1 + 0x10));
      goto _L0;
    }
    if (bVar1 == 0x42) {
      *puVar3 = **(undefined1 **)(param_1 + 0x10);
      memcpy(puVar3 + 1,*(byte **)(param_1 + 0x10) + 1,(uint)**(byte **)(param_1 + 0x10));
      puVar3 = puVar3 + 1 + **(byte **)(param_1 + 0x10);
      goto _L0;
    }
    if (bVar1 == 0x29) {
      puVar3 = (undefined1 *)zb_put_next_htole16(**(undefined2 **)(param_1 + 0x10));
      goto _L0;
    }
  }
  uVar4 = esp_log_timestamp();
  esp_log_write(1,"ESP_ZIGBEE_COMMAND",&_LC1,uVar4,"ESP_ZIGBEE_COMMAND");
_L0:
  zb_zcl_finish_and_send_packet
            (uVar2,puVar3,param_1,*(undefined1 *)(param_1 + 0xc),*(undefined1 *)(param_1 + 8),
             *(undefined1 *)(param_1 + 9),0x104,*(undefined2 *)(param_1 + 0x16));
  return;
}

