/*
 * Last changed at upstream commit c1113e88ee047f0eb31a91352a6fd0fc5318b6fd
 * https://github.com/espressif/esp-zigbee-sdk/commit/c1113e88ee047f0eb31a91352a6fd0fc5318b6fd
 * Upstream date: 2023-08-30 15:00:29 +0800
 * Upstream subject: esp-zigbee-sdk: release/v0.9.3(6da46788)
 * Source: libesp_zb_api_zczr -> esp_zigbee_core.o -> zb_zcl_endpoint_handler_callback
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int zb_zcl_endpoint_handler_callback(int param_1)

{
  undefined2 uVar1;
  undefined2 uVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  
  uVar6 = param_1 - 1U & 0xff;
  iVar3 = zb_bufpool_storage_bufid_to_buf(uVar6);
  uVar1 = *(undefined2 *)(iVar3 + 4);
  iVar3 = zb_bufpool_storage_bufid_to_buf(uVar6);
  uVar2 = *(undefined2 *)(iVar3 + 6);
  if (zcl_cli_resp_user_cb == (code *)0x0) {
    iVar3 = zb_buf_get_tail_func(param_1,0x1b);
    if (*(char *)(iVar3 + 0x16) == '\0') {
      iVar3 = zb_buf_get_tail_func(param_1,0x1b);
      if (*(ushort *)(iVar3 + 0xf) < 0xfc00) {
        for (uVar5 = 0; uVar5 < 3; uVar5 = uVar5 + 1) {
          if ((&s_endpoint_handler_table)[uVar5 * 4] == *(ushort *)(iVar3 + 0xf)) {
            iVar3 = (*(code *)(&PTR_zb_zcl_group_cluster_resp_handler_000155bc)[uVar5 * 2])
                              (param_1,(&PTR_zb_zcl_group_cluster_resp_handler_000155bc)[uVar5 * 2])
            ;
            goto _L0;
          }
        }
        iVar3 = 0;
_L0:
        if (iVar3 == 0) {
          iVar3 = zb_zcl_privilege_command_handler(param_1);
        }
      }
      else {
        iVar3 = zb_zcl_custom_cluster_handler(param_1);
      }
    }
    else {
      iVar3 = zb_zcl_general_cmd_handler(param_1);
    }
    iVar4 = zb_bufpool_storage_bufid_to_buf(uVar6);
    *(char *)(iVar4 + 4) = (char)uVar1;
    *(char *)(iVar4 + 5) = (char)((ushort)uVar1 >> 8);
    iVar4 = zb_bufpool_storage_bufid_to_buf(uVar6);
    *(char *)(iVar4 + 6) = (char)uVar2;
    *(char *)(iVar4 + 7) = (char)((ushort)uVar2 >> 8);
    if (iVar3 == 0) {
      if (zcl_raw_command_cb != (code *)0x0) {
        iVar3 = (*zcl_raw_command_cb)(param_1);
      }
      if (iVar3 == 0) {
        return 0;
      }
    }
    zb_buf_free_func(param_1);
  }
  else {
    iVar3 = (*zcl_cli_resp_user_cb)(param_1);
  }
  return iVar3;
}

