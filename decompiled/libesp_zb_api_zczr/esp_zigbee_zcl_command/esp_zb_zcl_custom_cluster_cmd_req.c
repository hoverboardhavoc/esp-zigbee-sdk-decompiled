/*
 * Last changed at upstream commit b278a1511ed728943e19c371f88a01e9d130f19f
 * https://github.com/espressif/esp-zigbee-sdk/commit/b278a1511ed728943e19c371f88a01e9d130f19f
 * Upstream date: 2023-02-27 14:43:05 +0800
 * Upstream subject: zcl: add ZCL API for color and report attribute(af3fa1e)
 * Source: libesp_zb_api_zczr -> esp_zigbee_zcl_command.o -> esp_zb_zcl_custom_cluster_cmd_req
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void esp_zb_zcl_custom_cluster_cmd_req(int param_1)

{
  undefined1 *puVar1;
  undefined4 uVar2;
  undefined1 *puVar3;
  undefined4 uVar4;
  uint uVar5;
  
  uVar2 = zb_buf_get_out_func();
  puVar3 = (undefined1 *)zb_zcl_start_command_header(1,0,*(undefined1 *)(param_1 + 0x1a),0);
  *puVar3 = (char)*(undefined4 *)(param_1 + 0x14);
  uVar5 = *(uint *)(param_1 + 0x14);
  if (uVar5 == 0x28) {
    puVar3[1] = 0;
    puVar3[2] = **(undefined1 **)(param_1 + 0x10);
    puVar1 = puVar3 + 3;
    goto _L0;
  }
  puVar1 = puVar3 + 1;
  if (uVar5 < 0x29) {
    if (uVar5 == 0x21) {
      puVar3[1] = 0;
      puVar1 = (undefined1 *)zb_put_next_htole16(puVar3 + 2,**(undefined2 **)(param_1 + 0x10));
      goto _L0;
    }
    if (uVar5 == 0x23) {
      puVar3[1] = 0;
      puVar1 = (undefined1 *)zb_put_next_htole32(puVar3 + 2,**(undefined4 **)(param_1 + 0x10));
      goto _L0;
    }
    if (uVar5 == 0x20) {
      puVar3[1] = 0;
      puVar3[2] = **(undefined1 **)(param_1 + 0x10);
      puVar1 = puVar3 + 3;
      goto _L0;
    }
  }
  else {
    if (uVar5 == 0x2b) {
      puVar3[1] = 0;
      puVar1 = (undefined1 *)zb_put_next_htole32(puVar3 + 2,**(undefined4 **)(param_1 + 0x10));
      goto _L0;
    }
    if (uVar5 == 0x42) {
      puVar3[1] = **(undefined1 **)(param_1 + 0x10);
      puVar3[2] = **(undefined1 **)(param_1 + 0x10);
      memcpy(puVar3 + 3,*(byte **)(param_1 + 0x10) + 1,(uint)**(byte **)(param_1 + 0x10));
      puVar1 = puVar3 + 3 + **(byte **)(param_1 + 0x10);
      goto _L0;
    }
    if (uVar5 == 0x29) {
      puVar3[1] = 0;
      puVar1 = (undefined1 *)zb_put_next_htole16(puVar3 + 2,**(undefined2 **)(param_1 + 0x10));
      goto _L0;
    }
  }
  uVar4 = esp_log_timestamp();
  esp_log_write(1,0x10000,&_L0,uVar4,0x10000);
_L0:
  zb_zcl_finish_and_send_packet
            (uVar2,puVar1,param_1,*(undefined1 *)(param_1 + 0xc),*(undefined1 *)(param_1 + 8),
             *(undefined1 *)(param_1 + 9),0x104,*(undefined2 *)(param_1 + 0x18));
  return;
}

