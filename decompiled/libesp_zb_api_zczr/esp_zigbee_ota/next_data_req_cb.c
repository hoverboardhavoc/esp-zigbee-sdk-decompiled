/*
 * Last changed at upstream commit dfdf370f9265e944dde2de8bee7a248c7515f1ef
 * https://github.com/espressif/esp-zigbee-sdk/commit/dfdf370f9265e944dde2de8bee7a248c7515f1ef
 * Upstream date: 2022-12-14 19:24:05 +0800
 * Upstream subject: examples:Add ota application example(986c075)
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
    *param_3 = (int)(&DAT_000102f0 + param_1);
  }
  else if ((param_1 < 0x38) && (0x38 < param_2 + param_1)) {
    __dest = malloc(param_2);
    memcpy(__dest,&DAT_000102f0 + param_1,0x38 - param_1);
    memcpy((void *)((int)__dest + (0x38 - param_1)),DAT_00010328,(param_1 - 0x38) + param_2);
    *param_3 = (int)__dest;
  }
  else if (0x38 < param_1) {
    if (is_free_0 == '\0') {
      is_free_0 = '\x01';
    }
    *param_3 = (int)DAT_00010328 + (param_1 - 0x38);
  }
  return 0;
}

