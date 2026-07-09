/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> zdo_nwk_mgmt.o -> zdo_op_nwk_mgmt_rtg_rsp
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

uint zdo_op_nwk_mgmt_rtg_rsp(int param_1,byte *param_2,int param_3)

{
  ushort uVar1;
  int iVar2;
  uint uVar3;
  void *pvVar4;
  ushort *puVar5;
  uint uVar6;
  uint unaff_s3;
  uint uVar7;
  byte bStack_23;
  ushort uStack_22;
  
  if ((param_1 == 0) || (param_2 == (byte *)0x0)) {
    __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/zdo/zdo_nwk_mgmt.c",0xf6,
                  "zdo_op_nwk_mgmt_rtg_rsp","payload && rsp");
  }
  else {
    if (param_3 == 0) {
      uStack_22 = 0;
      uVar3 = zmsg_get_length();
      af_read_le8(param_1,&uStack_22,param_2);
      if (*param_2 != 0) {
        return 0;
      }
      af_read_le8(param_1,&uStack_22,param_2 + 1);
      af_read_le8(param_1,&uStack_22,param_2 + 2);
      af_read_le8(param_1,&uStack_22,param_2 + 3);
      if (uVar3 < uStack_22) {
        return 0xfe;
      }
      if (param_2[3] == 0) {
        return 0;
      }
      pvVar4 = calloc((uint)param_2[3],6);
      *(void **)(param_2 + 4) = pvVar4;
      if (pvVar4 != (void *)0x0) {
        uVar7 = 0;
        while( true ) {
          if (param_2[3] <= uVar7) {
            return 0;
          }
          bStack_23 = 0;
          iVar2 = uVar7 * 6;
          af_read_le16(param_1,&uStack_22,*(int *)(param_2 + 4) + iVar2);
          af_read_le8(param_1,&uStack_22,&bStack_23);
          af_read_le16(param_1,&uStack_22,*(int *)(param_2 + 4) + iVar2 + 4);
          if (uVar3 < uStack_22) break;
          uVar6 = (uint)bStack_23;
          *(byte *)(*(int *)(param_2 + 4) + iVar2 + 2) =
               *(byte *)(*(int *)(param_2 + 4) + iVar2 + 2) & 0xf8 | bStack_23 & 7;
          *(byte *)(*(int *)(param_2 + 4) + iVar2 + 2) =
               *(byte *)(*(int *)(param_2 + 4) + iVar2 + 2) & 0xf7 |
               (byte)(((int)uVar6 >> 3 & 1U) << 3);
          *(byte *)(*(int *)(param_2 + 4) + iVar2 + 2) =
               *(byte *)(*(int *)(param_2 + 4) + iVar2 + 2) & 0xef |
               (byte)(((int)uVar6 >> 4 & 1U) << 4);
          *(byte *)(*(int *)(param_2 + 4) + iVar2 + 2) =
               (byte)(((int)uVar6 >> 5 & 1U) << 5) |
               *(byte *)(*(int *)(param_2 + 4) + iVar2 + 2) & 0xdf;
          uVar7 = uVar7 + 1 & 0xff;
        }
        return 0xfe;
      }
      return 0xfe;
    }
    uStack_22 = CONCAT11(uStack_22._1_1_,*param_2);
    iVar2 = zmsg_append_bytes(1,&uStack_22);
    if (iVar2 != 0) {
      return 0x8a;
    }
    unaff_s3 = (uint)*param_2;
    if (unaff_s3 != 0) {
      return 0;
    }
  }
  uStack_22._0_1_ = param_2[1];
  iVar2 = zmsg_append_bytes(param_1,1,&uStack_22);
  if (iVar2 == 0) {
    uStack_22._0_1_ = param_2[2];
    iVar2 = zmsg_append_bytes(param_1,1,&uStack_22);
    if (iVar2 == 0) {
      uStack_22 = CONCAT11(uStack_22._1_1_,param_2[3]);
      iVar2 = zmsg_append_bytes(param_1,1,&uStack_22);
      if (iVar2 == 0) {
        if (*(int *)(param_2 + 4) != 0) {
          uVar3 = unaff_s3;
          if (param_2[3] == 0) {
            unaff_s3 = 0;
          }
          else {
            for (; uVar3 < param_2[3]; uVar3 = uVar3 + 1 & 0xff) {
              puVar5 = (ushort *)(*(int *)(param_2 + 4) + uVar3 * 6);
              uVar1 = puVar5[1];
              uStack_22 = *puVar5;
              iVar2 = zmsg_append_bytes(param_1,2,&uStack_22);
              if (iVar2 != 0) {
                return 0x8a;
              }
              uStack_22 = CONCAT11(uStack_22._1_1_,
                                   (byte)uVar1 & 7 | (byte)((uVar1 >> 3 & 1) << 3) |
                                   (byte)((uVar1 >> 4 & 1) << 4) | (byte)((uVar1 >> 5 & 1) << 5));
              iVar2 = zmsg_append_bytes(param_1,1,&uStack_22);
              if (iVar2 != 0) {
                return 0x8a;
              }
              uStack_22 = *(ushort *)(*(int *)(param_2 + 4) + uVar3 * 6 + 4);
              iVar2 = zmsg_append_bytes(param_1,2,&uStack_22);
              if (iVar2 != 0) {
                return 0x8a;
              }
            }
          }
        }
      }
      else {
        unaff_s3 = 0x8a;
      }
    }
    else {
      unaff_s3 = 0x8a;
    }
  }
  else {
    unaff_s3 = 0x8a;
  }
  return unaff_s3;
}

