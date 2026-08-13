/*
 * Last changed at upstream commit ecca8a8cee0ba565a3b8dbe9d288517b724f31a9
 * https://github.com/espressif/esp-zigbee-sdk/commit/ecca8a8cee0ba565a3b8dbe9d288517b724f31a9
 * Upstream date: 2026-08-13 06:13:24 +0000
 * Upstream subject: change: update esp-zigbee-lib (e4bad48f)
 * Source: libesp-zigbee-core.zczr.release -> zdo_nwk_mgmt.o -> zdo_nwk_mgmt_rsp_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int zdo_nwk_mgmt_rsp_handler(int param_1)

{
  ushort uVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  byte bStack_4d;
  ushort auStack_4c [2];
  undefined4 uStack_48;
  void *pvStack_44;
  
  if (param_1 == 0) {
    return 0x80;
  }
  uVar1 = *(ushort *)(param_1 + 6);
  if (uVar1 == 0x8034) {
    uStack_48 = uStack_48 & 0xffffff00;
    if ((*(int *)(param_1 + 0x14) == 0) ||
       (iVar2 = zdo_op_nwk_mgmt_leave_rsp(&uStack_48,0), iVar2 != 0)) {
      return 0xfe;
    }
_L0:
    zdo_cb_nwk_mgmt_lqi_rsp_isra_0(&uStack_48,param_1 + 8);
    return iVar2;
  }
  if (0x8034 < uVar1) {
    if (uVar1 == 0x8036) {
      iVar2 = *(int *)(param_1 + 0x14);
      auStack_4c[0] = auStack_4c[0] & 0xff00;
      if (iVar2 == 0) {
        return 0xfe;
      }
      uStack_48 = uStack_48 & 0xffff0000;
      uVar3 = zmsg_get_length(iVar2);
      af_read_le8_isra_0(iVar2,&uStack_48,auStack_4c);
      if (uVar3 < (uStack_48 & 0xffff)) {
        return 0xfe;
      }
      zdo_cb_nwk_mgmt_lqi_rsp_isra_0(auStack_4c,param_1 + 8);
      return 0;
    }
    if (uVar1 != 0x8038) {
      return 0x84;
    }
    memset(&uStack_48,0,0x28);
    if (*(int *)(param_1 + 0x14) == 0) {
      return 0xfe;
    }
    iVar2 = zdo_op_nwk_mgmt_nwk_update_notify(&uStack_48,0);
    if (iVar2 != 0) {
      return iVar2;
    }
    goto _L0;
  }
  if (uVar1 == 0x8032) {
    iVar2 = *(int *)(param_1 + 0x14);
    uStack_48 = 0;
    pvStack_44 = (void *)0x0;
    if (iVar2 != 0) {
      auStack_4c[0] = 0;
      uVar3 = zmsg_get_length(iVar2);
      af_read_le8_isra_0(iVar2,auStack_4c,&uStack_48);
      if ((uStack_48 & 0xff) == 0) {
        af_read_le8_isra_0(iVar2,auStack_4c,(int)&uStack_48 + 1);
        af_read_le8_isra_0(iVar2,auStack_4c,(int)&uStack_48 + 2);
        af_read_le8_isra_0(iVar2,auStack_4c,(int)&uStack_48 + 3);
        if (uVar3 < auStack_4c[0]) goto _L0;
        if (uStack_48 >> 0x18 != 0) {
          pvStack_44 = calloc(uStack_48 >> 0x18,6);
          uVar4 = 0;
          if (pvStack_44 == (void *)0x0) goto _L0;
          for (; uVar4 < uStack_48 >> 0x18; uVar4 = uVar4 + 1 & 0xff) {
            iVar5 = uVar4 * 6;
            bStack_4d = 0;
            af_read_le16_isra_0(iVar2,auStack_4c,(void *)((int)pvStack_44 + iVar5));
            af_read_le8_isra_0(iVar2,auStack_4c,&bStack_4d);
            af_read_le16_isra_0(iVar2,auStack_4c,(int)pvStack_44 + iVar5 + 4);
            if (uVar3 < auStack_4c[0]) goto _L0;
            *(byte *)((int)pvStack_44 + iVar5 + 2) =
                 bStack_4d & 0x3f | *(byte *)((int)pvStack_44 + iVar5 + 2) & 0xc0;
          }
        }
      }
      zdo_cb_nwk_mgmt_lqi_rsp_isra_0(&uStack_48,param_1 + 8);
      iVar2 = 0;
      goto _L0;
    }
  }
  else {
    if (uVar1 != 0x8033) {
      if (uVar1 != 0x8031) {
        return 0x84;
      }
      iVar2 = zdo_nwk_mgmt_lqi_rsp_handler();
      return iVar2;
    }
    uStack_48 = 0;
    pvStack_44 = (void *)0x0;
    if ((*(int *)(param_1 + 0x14) != 0) &&
       (iVar2 = zdo_op_nwk_mgmt_bind_rsp(&uStack_48,0), iVar2 == 0)) {
      zdo_cb_nwk_mgmt_lqi_rsp_isra_0(&uStack_48,param_1 + 8);
      iVar2 = 0;
      goto _L0;
    }
  }
_L0:
  iVar2 = 0xfe;
_L0:
  if (pvStack_44 != (void *)0x0) {
    mm_free();
    return iVar2;
  }
  return iVar2;
}

