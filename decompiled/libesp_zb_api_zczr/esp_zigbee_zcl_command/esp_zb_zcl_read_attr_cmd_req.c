/*
 * Last changed at upstream commit 37b2129eea9960f95d70bf2e6607337834e2750d
 * https://github.com/espressif/esp-zigbee-sdk/commit/37b2129eea9960f95d70bf2e6607337834e2750d
 * Upstream date: 2023-10-10 17:40:24 +0800
 * Upstream subject: esp-zigbee-sdk: release/v1.0.0(8d71c0ae)
 * Source: libesp_zb_api_zczr -> esp_zigbee_zcl_command.o -> esp_zb_zcl_read_attr_cmd_req
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void esp_zb_zcl_read_attr_cmd_req(int param_1)

{
  char cVar1;
  int iVar2;
  undefined4 uVar3;
  undefined1 *puVar4;
  char *pcVar5;
  
  uVar3 = zb_buf_get_out_func();
  puVar4 = (undefined1 *)zb_buf_reuse_func();
  *puVar4 = 0;
  pcVar5 = (char *)zb_zcl_get_ctx();
  cVar1 = *pcVar5;
  *pcVar5 = cVar1 + '\x01';
  puVar4[1] = cVar1;
  puVar4[2] = 0;
  puVar4 = puVar4 + 3;
  iVar2 = 0;
  while ((iVar2 < (int)(uint)*(byte *)(param_1 + 0x12) && (*(int *)(param_1 + 0x14) != 0))) {
    puVar4 = (undefined1 *)
             zb_put_next_htole16(*(undefined2 *)(*(int *)(param_1 + 0x14) + iVar2 * 2));
    iVar2 = iVar2 + 1;
  }
  zb_zcl_finish_and_send_packet
            (uVar3,puVar4,param_1,*(undefined1 *)(param_1 + 0xc),*(undefined1 *)(param_1 + 8),
             *(undefined1 *)(param_1 + 9),0x104,*(undefined2 *)(param_1 + 0x10));
  return;
}

