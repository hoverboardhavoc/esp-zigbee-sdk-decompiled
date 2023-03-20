/*
 * Last changed at upstream commit 8f416d47159477fb2dfe72f817700bc25debb587
 * https://github.com/espressif/esp-zigbee-sdk/commit/8f416d47159477fb2dfe72f817700bc25debb587
 * Upstream date: 2023-03-20 14:23:27 +0800
 * Upstream subject: zcl: support more ZCL cluster(caef391)
 * Source: libesp_zb_api_zczr -> esp_zigbee_ota.o -> next_data_req_cb
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 next_data_req_cb(uint param_1,size_t param_2,int *param_3)

{
  void *__dest;
  
  if (param_2 + param_1 < 0x38) {
    *param_3 = (int)(&ota_config + param_1);
  }
  else if ((param_1 < 0x38) && (0x38 < param_2 + param_1)) {
    __dest = malloc(param_2);
    memcpy(__dest,&ota_config + param_1,0x38 - param_1);
    memcpy((void *)((int)__dest + (0x38 - param_1)),DAT_00010330,(param_1 - 0x38) + param_2);
    *param_3 = (int)__dest;
  }
  else if (0x38 < param_1) {
    if (is_free_0 == '\0') {
      is_free_0 = '\x01';
    }
    *param_3 = (int)DAT_00010330 + (param_1 - 0x38);
  }
  return 0;
}

