/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> time.o -> zcl_time_cluster_read_time
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

zcl_status_t zcl_time_cluster_read_time(uint8_t ep_id,uint16_t attr_id,uint32_t *time)

{
  ezb_zcl_time_interface_t *peVar1;
  uint32_t uVar2;
  zcl_attr_desc_t *pzVar3;
  undefined2 in_register_0000202e;
  _func_uint32_t *p_Var4;
  int iVar5;
  int iVar6;
  uint uVar7;
  uint uVar8;
  
  iVar5 = CONCAT22(in_register_0000202e,attr_id);
  if (time == (uint32_t *)0x0) {
    return 0x87;
  }
  peVar1 = time_server_get_interface(ep_id);
  p_Var4 = peVar1->get_utc_time;
  if (p_Var4 == (_func_uint32_t *)0x0) {
    return 0x8b;
  }
  if (iVar5 == 6) {
    pzVar3 = time_server_get_attr_desc(ep_id,2);
    p_Var4 = peVar1->get_utc_time;
    if ((pzVar3 != (zcl_attr_desc_t *)0x0) && (pzVar3->data_p != (void *)0x0)) {
      uVar2 = (*p_Var4)();
                    /* WARNING: Load size is inaccurate */
      uVar2 = *pzVar3->data_p + uVar2;
      goto _L0;
    }
  }
  else {
    if (iVar5 == 7) {
      uVar2 = (*p_Var4)();
      *time = uVar2;
      pzVar3 = time_server_get_attr_desc(ep_id,2);
      iVar5 = 0;
      if ((pzVar3 != (zcl_attr_desc_t *)0x0) && ((int *)pzVar3->data_p != (int *)0x0)) {
                    /* WARNING: Load size is inaccurate */
        iVar5 = *pzVar3->data_p;
      }
      uVar2 = *time;
      pzVar3 = time_server_get_attr_desc(ep_id,3);
      uVar8 = 0xffffffff;
      if ((pzVar3 != (zcl_attr_desc_t *)0x0) && ((uint *)pzVar3->data_p != (uint *)0x0)) {
                    /* WARNING: Load size is inaccurate */
        uVar8 = *pzVar3->data_p;
      }
      pzVar3 = time_server_get_attr_desc(ep_id,4);
      uVar7 = 0xffffffff;
      if ((pzVar3 != (zcl_attr_desc_t *)0x0) && ((uint *)pzVar3->data_p != (uint *)0x0)) {
                    /* WARNING: Load size is inaccurate */
        uVar7 = *pzVar3->data_p;
      }
      pzVar3 = time_server_get_attr_desc(ep_id,5);
      iVar6 = 0;
      if ((pzVar3 != (zcl_attr_desc_t *)0x0) && ((int *)pzVar3->data_p != (int *)0x0)) {
                    /* WARNING: Load size is inaccurate */
        iVar6 = *pzVar3->data_p;
      }
      if ((((uVar8 == 0xffffffff) || (uVar7 == 0xffffffff)) || (*time < uVar8)) || (uVar7 < *time))
      {
        *time = iVar5 + uVar2;
        return '\0';
      }
      uVar2 = iVar6 + iVar5 + uVar2;
_L0:
      *time = uVar2;
      return '\0';
    }
    if (iVar5 != 0) {
      return '\0';
    }
  }
  uVar2 = (*p_Var4)();
  *time = uVar2;
  return '\0';
}

