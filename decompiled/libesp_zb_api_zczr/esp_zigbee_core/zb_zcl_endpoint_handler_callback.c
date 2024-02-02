/*
 * Last changed at upstream commit 2e2b779251f791b76c34cc582bf68595de9ac19b
 * https://github.com/espressif/esp-zigbee-sdk/commit/2e2b779251f791b76c34cc582bf68595de9ac19b
 * Upstream date: 2024-02-02 22:15:44 +0800
 * Upstream subject: feat(spinel): support zigbee radio spinel
 * Source: libesp_zb_api_zczr -> esp_zigbee_core.o -> zb_zcl_endpoint_handler_callback
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void zb_zcl_endpoint_handler_callback(int param_1)

{
  short sVar1;
  short sVar2;
  int iVar3;
  undefined4 uVar4;
  uint uVar5;
  uint uVar6;
  
  uVar6 = param_1 - 1U & 0xff;
  iVar3 = zb_bufpool_storage_bufid_to_buf(uVar6);
  sVar1 = *(short *)(iVar3 + 4);
  iVar3 = zb_bufpool_storage_bufid_to_buf(uVar6);
  sVar2 = *(short *)(iVar3 + 6);
  if (zcl_cli_resp_user_cb == (code *)0x0) {
    iVar3 = zb_buf_get_tail_func(param_1,0x1b);
    if (*(char *)(iVar3 + 0x16) == '\0') {
      iVar3 = zb_buf_get_tail_func(param_1,0x1b);
      if (*(ushort *)(iVar3 + 0xf) < 0xfc00) {
        for (uVar5 = 0; uVar5 < 3; uVar5 = uVar5 + 1) {
          if ((&s_endpoint_handler_table)[uVar5 * 4] == *(ushort *)(iVar3 + 0xf)) {
            iVar3 = (*(code *)(&PTR_zb_zcl_group_cluster_resp_handler_000176d0)[uVar5 * 2])
                              (param_1,(&PTR_zb_zcl_group_cluster_resp_handler_000176d0)[uVar5 * 2])
            ;
            goto _L0;
          }
        }
        iVar3 = 0;
_L0:
        if (iVar3 != 0) {
          return;
        }
        iVar3 = zb_zcl_privilege_command_handler(param_1);
      }
      else {
        iVar3 = zb_zcl_custom_cluster_handler(param_1);
      }
    }
    else {
      iVar3 = zb_zcl_general_cmd_handler(param_1);
    }
    if ((iVar3 == 0) && (zcl_raw_command_cb != (code *)0x0)) {
      iVar3 = zb_bufpool_storage_bufid_to_buf(uVar6);
      if ((*(short *)(iVar3 + 4) != sVar1) ||
         (iVar3 = zb_bufpool_storage_bufid_to_buf(uVar6), *(short *)(iVar3 + 6) != sVar2)) {
        iVar3 = zb_bufpool_storage_bufid_to_buf(uVar6);
        *(char *)(iVar3 + 4) = (char)sVar1;
        *(char *)(iVar3 + 5) = (char)((ushort)sVar1 >> 8);
        iVar3 = zb_bufpool_storage_bufid_to_buf(uVar6);
        *(char *)(iVar3 + 6) = (char)sVar2;
        *(char *)(iVar3 + 7) = (char)((ushort)sVar2 >> 8);
        uVar4 = esp_log_timestamp();
        esp_log_write(2,"ESP_ZIGBEE_CORE",&_LC32,uVar4,"ESP_ZIGBEE_CORE");
      }
      (*zcl_raw_command_cb)(param_1,zcl_raw_command_cb);
    }
  }
  else {
    (*zcl_cli_resp_user_cb)(param_1);
  }
  return;
}

