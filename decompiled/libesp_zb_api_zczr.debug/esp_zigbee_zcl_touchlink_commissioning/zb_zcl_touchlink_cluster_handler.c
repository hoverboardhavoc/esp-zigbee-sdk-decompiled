/*
 * Last changed at upstream commit e28462af08968da8dbda59a317df742f0109ee5f
 * https://github.com/espressif/esp-zigbee-sdk/commit/e28462af08968da8dbda59a317df742f0109ee5f
 * Upstream date: 2024-04-12 14:44:19 +0800
 * Upstream subject: esp-zigbee-sdk: release/v1.2.3(042315bf)
 * Source: libesp_zb_api_zczr.debug -> esp_zigbee_zcl_touchlink_commissioning.o -> zb_zcl_touchlink_cluster_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 zb_zcl_touchlink_cluster_handler(undefined4 param_1)

{
  char cVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  
  iVar2 = zb_buf_get_tail_func(0x1b);
  if (iVar2 == 0) {
    uVar3 = 0;
  }
  else if (*(char *)(iVar2 + 0x14) == '\x01') {
    cVar1 = *(char *)(iVar2 + 0x13);
    if (cVar1 == 'A') {
      iVar4 = zcl_touchlink_get_group_identifiers_resp_handler(param_1);
    }
    else if (cVar1 == 'B') {
      iVar4 = zcl_touchlink_get_endpoint_list_resp_handler(param_1);
    }
    else {
      if (cVar1 != '@') {
        uVar3 = esp_log_timestamp();
        esp_log_write(2,0x10000,&_LC8,uVar3,0x10000,*(undefined1 *)(iVar2 + 0x13));
        return 0;
      }
      zcl_touchlink_endpoint_info_handler(param_1);
      iVar4 = 0;
    }
    zb_zcl_send_default_handler(param_1,iVar2,iVar4 != 0);
    uVar3 = 1;
  }
  else if (*(char *)(iVar2 + 0x14) == '\0') {
    if (*(char *)(iVar2 + 0x13) == 'A') {
      iVar4 = zcl_touchlink_get_group_identifiers_req_handler(param_1);
    }
    else {
      if (*(char *)(iVar2 + 0x13) != 'B') {
        uVar3 = esp_log_timestamp();
        esp_log_write(2,0x10000,&_LC9,uVar3,0x10000,*(undefined1 *)(iVar2 + 0x13));
        return 0;
      }
      iVar4 = zcl_touchlink_get_endpoint_list_req_handler(param_1);
    }
    zb_zcl_send_default_handler(param_1,iVar2,iVar4 != 0);
    uVar3 = 1;
  }
  else {
    uVar3 = 0;
  }
  return uVar3;
}

