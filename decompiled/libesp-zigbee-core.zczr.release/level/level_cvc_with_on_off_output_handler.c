/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> level.o -> level_cvc_with_on_off_output_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void level_cvc_with_on_off_output_handler
               (uint8_t ep_id,int32_t output,uint32_t remaining_time,uintptr_t user_ctx)

{
  undefined4 uVar1;
  int iVar2;
  zcl_attr_desc_t *pzVar3;
  undefined3 in_register_00002029;
  uint uVar4;
  undefined1 uStack_11;
  
  level_cvc_output_handler(ep_id,output,remaining_time,user_ctx);
  iVar2 = ezb_zcl_get_attr_desc(6,1,0,0);
  pzVar3 = level_srv_get_attr_desc(ep_id,2);
  if (iVar2 != 0) {
    uVar4 = 0;
    if (pzVar3 != (zcl_attr_desc_t *)0x0) {
                    /* WARNING: Load size is inaccurate */
      uVar4 = (uint)*pzVar3->data_p;
    }
    if (uVar4 < (output & 0xffU)) {
      uStack_11 = 1;
      if (**(char **)(iVar2 + 8) == '\0') {
_L105:
        iVar2 = zcl_set_attr_value(6,1,0,0,&uStack_11,0);
        if (iVar2 == 0) {
          uVar1 = ezb_zcl_get_attr_desc(CONCAT31(in_register_00002029,ep_id),6,1,0,0);
          zcl_message_notify_attr_value(CONCAT31(in_register_00002029,ep_id),6,1,uVar1);
        }
        return;
      }
    }
    else if (**(char **)(iVar2 + 8) != '\0') {
      uStack_11 = 0;
      goto _L105;
    }
  }
  return;
}

