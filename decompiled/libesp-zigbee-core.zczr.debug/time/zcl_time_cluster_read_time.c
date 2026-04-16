/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> time.o -> zcl_time_cluster_read_time
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

zcl_status_t zcl_time_cluster_read_time(uint8_t ep_id,uint16_t attr_id,uint32_t *time)

{
  zcl_status_t zVar1;
  ezb_zcl_time_interface_t *peVar2;
  uint32_t uVar3;
  zcl_attr_desc_t *pzVar4;
  undefined2 in_register_0000202e;
  int iVar5;
  int iVar6;
  _func_uint32_t *p_Var7;
  uint uVar8;
  uint uVar9;
  
  iVar5 = CONCAT22(in_register_0000202e,attr_id);
  if (time == (uint32_t *)0x0) {
    zVar1 = 0x87;
  }
  else {
    peVar2 = time_server_get_interface(ep_id);
    p_Var7 = peVar2->get_utc_time;
    if (p_Var7 == (_func_uint32_t *)0x0) {
      zVar1 = 0x8b;
    }
    else if (iVar5 == 6) {
      pzVar4 = time_server_get_attr_desc(ep_id,2);
      if ((pzVar4 == (zcl_attr_desc_t *)0x0) || (pzVar4->data_p == (void *)0x0)) {
        uVar3 = (*peVar2->get_utc_time)(peVar2->get_utc_time);
        *time = uVar3;
        zVar1 = '\0';
      }
      else {
        uVar3 = (*peVar2->get_utc_time)(peVar2->get_utc_time);
                    /* WARNING: Load size is inaccurate */
        *time = uVar3 + *pzVar4->data_p;
        zVar1 = '\0';
      }
    }
    else if (iVar5 == 7) {
      uVar3 = (*p_Var7)();
      *time = uVar3;
      pzVar4 = time_server_get_attr_desc(ep_id,2);
      if (pzVar4 == (zcl_attr_desc_t *)0x0) {
        iVar5 = 0;
      }
      else if ((int *)pzVar4->data_p == (int *)0x0) {
        iVar5 = 0;
      }
      else {
                    /* WARNING: Load size is inaccurate */
        iVar5 = *pzVar4->data_p;
      }
      uVar3 = *time;
      pzVar4 = time_server_get_attr_desc(ep_id,3);
      if (pzVar4 == (zcl_attr_desc_t *)0x0) {
        uVar8 = 0xffffffff;
      }
      else if ((uint *)pzVar4->data_p == (uint *)0x0) {
        uVar8 = 0xffffffff;
      }
      else {
                    /* WARNING: Load size is inaccurate */
        uVar8 = *pzVar4->data_p;
      }
      pzVar4 = time_server_get_attr_desc(ep_id,4);
      if (pzVar4 == (zcl_attr_desc_t *)0x0) {
        uVar9 = 0xffffffff;
      }
      else if ((uint *)pzVar4->data_p == (uint *)0x0) {
        uVar9 = 0xffffffff;
      }
      else {
                    /* WARNING: Load size is inaccurate */
        uVar9 = *pzVar4->data_p;
      }
      pzVar4 = time_server_get_attr_desc(ep_id,5);
      if (pzVar4 == (zcl_attr_desc_t *)0x0) {
        iVar6 = 0;
      }
      else if ((int *)pzVar4->data_p == (int *)0x0) {
        iVar6 = 0;
      }
      else {
                    /* WARNING: Load size is inaccurate */
        iVar6 = *pzVar4->data_p;
      }
      if ((((uVar8 == 0xffffffff) || (uVar9 == 0xffffffff)) || (*time < uVar8)) || (uVar9 < *time))
      {
        *time = uVar3 + iVar5;
        zVar1 = '\0';
      }
      else {
        *time = iVar6 + uVar3 + iVar5;
        zVar1 = '\0';
      }
    }
    else if (iVar5 == 0) {
      uVar3 = (*p_Var7)();
      *time = uVar3;
      zVar1 = '\0';
    }
    else {
      zVar1 = '\0';
    }
  }
  return zVar1;
}

