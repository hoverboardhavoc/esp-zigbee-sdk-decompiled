/*
 * Last changed at upstream commit bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * https://github.com/espressif/esp-zigbee-sdk/commit/bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * Upstream date: 2026-05-22 03:16:46 +0000
 * Upstream subject: change: update esp-zigbee-lib (73450389)
 * Source: libesp-zigbee-core.zczr.debug -> af_desc.o -> af_device_simple_desc_init
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

ezb_err_t af_device_simple_desc_init(af_ep_desc_t *ep_desc)

{
  zcl_cluster_desc_t *pzVar1;
  ezb_err_t eVar2;
  uint16_t *puVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  zcl_cluster_desc_t *pzVar7;
  
  if (ep_desc == (af_ep_desc_t *)0x0) {
    eVar2 = 2;
_L0:
    if ((ep_desc != (af_ep_desc_t *)0x0) &&
       ((ep_desc->simple_desc).app_cluster_list != (uint16_t *)0x0)) {
      mm_free();
      (ep_desc->simple_desc).app_cluster_list = (uint16_t *)0x0;
    }
  }
  else {
    pzVar1 = ep_desc->cluster_list;
    for (pzVar7 = pzVar1; pzVar7 != (zcl_cluster_desc_t *)0x0; pzVar7 = pzVar7->next) {
      if (pzVar7->role_mask == '\x01') {
        (ep_desc->simple_desc).app_input_cluster_count =
             (ep_desc->simple_desc).app_input_cluster_count + '\x01';
      }
      else {
        if (pzVar7->role_mask != '\x02') {
          __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/af/af_desc.c",0x2db,
                        "af_device_simple_desc_init",&_LC0);
          break;
        }
        (ep_desc->simple_desc).app_output_cluster_count =
             (ep_desc->simple_desc).app_output_cluster_count + '\x01';
      }
    }
    uVar4 = (uint)(ep_desc->simple_desc).app_input_cluster_count;
    iVar6 = uVar4 + (ep_desc->simple_desc).app_output_cluster_count;
    if (iVar6 != 0) {
      puVar3 = (uint16_t *)calloc(1,iVar6 * 2);
      (ep_desc->simple_desc).app_cluster_list = puVar3;
      if (puVar3 == (uint16_t *)0x0) {
        eVar2 = 1;
        goto _L0;
      }
      uVar5 = 0;
      for (; pzVar1 != (zcl_cluster_desc_t *)0x0; pzVar1 = pzVar1->next) {
        if (pzVar1->role_mask == '\x01') {
          (ep_desc->simple_desc).app_cluster_list[uVar5] = pzVar1->cluster_id;
          uVar5 = uVar5 + 1 & 0xffff;
        }
        else {
          if (pzVar1->role_mask != '\x02') {
            __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/af/af_desc.c",0x2ea,
                          "af_device_simple_desc_init",&_LC0);
            break;
          }
          (ep_desc->simple_desc).app_cluster_list[uVar4] = pzVar1->cluster_id;
          uVar4 = uVar4 + 1 & 0xffff;
        }
      }
    }
    af_add_simple_desc(&ep_desc->simple_desc);
    eVar2 = 0;
  }
  return eVar2;
}

