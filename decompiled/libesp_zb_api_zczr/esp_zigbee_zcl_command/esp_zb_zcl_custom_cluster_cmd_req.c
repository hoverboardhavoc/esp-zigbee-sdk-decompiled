/*
 * Last changed at upstream commit f1369f27c0afa51d13986c066b316e6812865b18
 * https://github.com/espressif/esp-zigbee-sdk/commit/f1369f27c0afa51d13986c066b316e6812865b18
 * Upstream date: 2023-10-23 12:06:56 +0800
 * Upstream subject: esp-zigbee-sdk: release/v1.0.1(00d5cde0)
 * Source: libesp_zb_api_zczr -> esp_zigbee_zcl_command.o -> esp_zb_zcl_custom_cluster_cmd_req
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void esp_zb_zcl_custom_cluster_cmd_req(int param_1)

{
  undefined4 uVar1;
  undefined1 *puVar2;
  undefined4 uVar3;
  uint uVar4;
  
  uVar1 = zb_buf_get_out_func();
  zb_zcl_start_command_header(1,0,*(undefined1 *)(param_1 + 0x1a),0);
  puVar2 = (undefined1 *)zb_put_next_htole32(*(undefined4 *)(param_1 + 0x14));
  uVar4 = *(uint *)(param_1 + 0x14);
  if (uVar4 == 0x28) {
    *puVar2 = 1;
    puVar2[1] = **(undefined1 **)(param_1 + 0x10);
    puVar2 = puVar2 + 2;
    goto _L0;
  }
  if (uVar4 < 0x29) {
    if (uVar4 == 0x21) {
      *puVar2 = 2;
      puVar2 = (undefined1 *)zb_put_next_htole16(puVar2 + 1,**(undefined2 **)(param_1 + 0x10));
      goto _L0;
    }
    if (uVar4 == 0x23) {
      *puVar2 = 4;
      puVar2 = (undefined1 *)zb_put_next_htole32(puVar2 + 1,**(undefined4 **)(param_1 + 0x10));
      goto _L0;
    }
    if (uVar4 == 0x20) {
      *puVar2 = 1;
      puVar2[1] = **(undefined1 **)(param_1 + 0x10);
      puVar2 = puVar2 + 2;
      goto _L0;
    }
  }
  else {
    if (uVar4 == 0x2b) {
      *puVar2 = 4;
      puVar2 = (undefined1 *)zb_put_next_htole32(puVar2 + 1,**(undefined4 **)(param_1 + 0x10));
      goto _L0;
    }
    if (uVar4 == 0x42) {
      *puVar2 = **(undefined1 **)(param_1 + 0x10);
      puVar2[1] = **(undefined1 **)(param_1 + 0x10);
      memcpy(puVar2 + 2,*(byte **)(param_1 + 0x10) + 1,(uint)**(byte **)(param_1 + 0x10));
      puVar2 = puVar2 + 2 + **(byte **)(param_1 + 0x10);
      goto _L0;
    }
    if (uVar4 == 0x29) {
      *puVar2 = 2;
      puVar2 = (undefined1 *)zb_put_next_htole16(puVar2 + 1,**(undefined2 **)(param_1 + 0x10));
      goto _L0;
    }
  }
  uVar3 = esp_log_timestamp();
  esp_log_write(1,0x10000,&_LC7,uVar3,0x10000,*(undefined4 *)(param_1 + 0x14));
_L0:
  zb_zcl_finish_and_send_packet
            (uVar1,puVar2,param_1,*(undefined1 *)(param_1 + 0xc),*(undefined1 *)(param_1 + 8),
             *(undefined1 *)(param_1 + 9),0x104,*(undefined2 *)(param_1 + 0x18));
  return;
}

