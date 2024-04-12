/*
 * Last changed at upstream commit e28462af08968da8dbda59a317df742f0109ee5f
 * https://github.com/espressif/esp-zigbee-sdk/commit/e28462af08968da8dbda59a317df742f0109ee5f
 * Upstream date: 2024-04-12 14:44:19 +0800
 * Upstream subject: esp-zigbee-sdk: release/v1.2.3(042315bf)
 * Source: libesp_zb_api_zczr.debug -> esp_zigbee_zcl_touchlink_commissioning.o -> zcl_touchlink_endpoint_info_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 zcl_touchlink_endpoint_info_handler(undefined4 param_1)

{
  char cVar1;
  char cVar2;
  char cVar3;
  uint uVar4;
  void *__src;
  int iVar5;
  undefined1 *puVar6;
  undefined4 uVar7;
  undefined1 auStack_4c [28];
  undefined1 uStack_30;
  undefined1 uStack_2f;
  undefined1 uStack_2e;
  undefined1 uStack_2d;
  undefined1 uStack_2c;
  undefined1 uStack_2b;
  undefined1 uStack_2a;
  undefined1 uStack_29;
  short sStack_28;
  char cStack_26;
  undefined1 uStack_25;
  undefined1 uStack_24;
  undefined1 uStack_23;
  undefined1 uStack_22;
  char cStack_21;
  
  __src = (void *)zb_buf_get_tail_func(0x1b);
  memcpy(auStack_4c,__src,0x1b);
  iVar5 = zb_buf_len_func(param_1);
  if (iVar5 == 0x10) {
    puVar6 = (undefined1 *)zb_buf_begin_func(param_1);
    uStack_30 = *puVar6;
    uStack_2f = puVar6[1];
    uStack_2e = puVar6[2];
    uStack_2d = puVar6[3];
    uStack_2c = puVar6[4];
    uStack_2b = puVar6[5];
    uStack_2a = puVar6[6];
    uStack_29 = puVar6[7];
    sStack_28 = *(short *)(puVar6 + 8);
    cVar1 = puVar6[10];
    uStack_25 = puVar6[0xb];
    uStack_24 = puVar6[0xc];
    uStack_23 = puVar6[0xd];
    uStack_22 = puVar6[0xe];
    cVar2 = puVar6[0xf];
    cStack_26 = cVar1;
    cStack_21 = cVar2;
    for (uVar4 = 0; uVar4 < 0x10; uVar4 = uVar4 + 1 & 0xff) {
      cVar3 = zb_touchlink_device_endpoint_information_record_list[uVar4 * 0x12 + 0x11];
      if ((((cVar3 != '\0') &&
           (iVar5 = memcmp(zb_touchlink_device_endpoint_information_record_list + uVar4 * 0x12,
                           &uStack_30,8), iVar5 == 0)) &&
          (*(short *)(zb_touchlink_device_endpoint_information_record_list + uVar4 * 0x12 + 8) ==
           sStack_28)) &&
         (((cVar1 == zb_touchlink_device_endpoint_information_record_list[uVar4 * 0x12 + 10] &&
           (*(short *)(zb_touchlink_device_endpoint_information_record_list + uVar4 * 0x12 + 0xc) ==
            CONCAT11(uStack_24,uStack_25))) &&
          (((uint3)*(ushort *)
                    (zb_touchlink_device_endpoint_information_record_list + uVar4 * 0x12 + 0xe) ==
            (uint3)(CONCAT12(uStack_22,CONCAT11(uStack_23,uStack_24)) >> 8) &&
           (cVar2 == zb_touchlink_device_endpoint_information_record_list[uVar4 * 0x12 + 0x10]))))))
      {
        return 0xffffffff;
      }
      if (cVar3 == '\0') {
        memcpy(zb_touchlink_device_endpoint_information_record_list + uVar4 * 0x12,&uStack_30,0x10);
        zb_touchlink_device_endpoint_information_record_list[uVar4 * 0x12 + 0x11] = 1;
        return 0;
      }
    }
  }
  else {
    uVar7 = esp_log_timestamp();
    esp_log_write(3,0x10000,&_LC5,uVar7,0x10000);
  }
  return 0xffffffff;
}

