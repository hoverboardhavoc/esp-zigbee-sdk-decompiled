/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> color_control.o -> schedule_cvc_color_space
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
  zcl_cvc_ctx_t *pzStack_18;
  zcl_cvc_ctx_t *second_cvc;
  zcl_cvc_ctx_t *first_cvc;
  
  pzVar2 = color_control_srv_get_attr_desc(ep_id,0xeff0);
  if (pzVar2 == (zcl_attr_desc_t *)0x0) {
    eVar1 = 0x86;
  }
  else {
    second_cvc = (zcl_cvc_ctx_t *)pzVar2->data_p;
    pzStack_18 = second_cvc + 1;
    zcl_cvc_stop();
    zcl_cvc_stop(pzStack_18);
    iVar3 = zcl_cvc_ctx_create(first_input,&second_cvc);
    if (iVar3 == 0) {
      eVar1 = '\x01';
    }
    else {
      iVar3 = zcl_cvc_ctx_create(second_input,&pzStack_18);
      if (iVar3 == 0) {
        eVar1 = '\x01';
      }
      else {
        zcl_cvc_start(second_cvc);
        zcl_cvc_start(pzStack_18);
        eVar1 = '\0';
      }
    }
  }
  return eVar1;
}

