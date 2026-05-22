/*
 * Last changed at upstream commit bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * https://github.com/espressif/esp-zigbee-sdk/commit/bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * Upstream date: 2026-05-22 03:16:46 +0000
 * Upstream subject: change: update esp-zigbee-lib (73450389)
 * Source: libesp-zigbee-core.zczr.release -> color_control.o -> schedule_cvc_color_space
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

ezb_zcl_status_t
schedule_cvc_color_space(uint8_t ep_id,zcl_cvc_input_t *first_input,zcl_cvc_input_t *second_input)

{
  ezb_zcl_status_t eVar1;
  zcl_attr_desc_t *pzVar2;
  int iVar3;
  void *pvStack_18;
  zcl_cvc_ctx_t *first_cvc;
  zcl_cvc_ctx_t *second_cvc;
  
  pzVar2 = color_control_srv_get_attr_desc(ep_id,(uint16_t)first_input);
  if (pzVar2 == (zcl_attr_desc_t *)0x0) {
    eVar1 = 0x86;
  }
  else {
    pvStack_18 = pzVar2->data_p;
    first_cvc = (zcl_cvc_ctx_t *)((int)pvStack_18 + 0x40);
    zcl_cvc_stop();
    zcl_cvc_stop(first_cvc);
    iVar3 = zcl_cvc_ctx_create(first_input,&pvStack_18);
    if ((iVar3 == 0) || (iVar3 = zcl_cvc_ctx_create(second_input,&first_cvc), iVar3 == 0)) {
      eVar1 = '\x01';
    }
    else {
      zcl_cvc_start(pvStack_18);
      zcl_cvc_start(first_cvc);
      eVar1 = '\0';
    }
  }
  return eVar1;
}

