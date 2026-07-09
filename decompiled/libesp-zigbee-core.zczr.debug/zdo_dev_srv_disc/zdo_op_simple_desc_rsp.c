/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> zdo_dev_srv_disc.o -> zdo_op_simple_desc_rsp
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

uint zdo_op_simple_desc_rsp(int param_1,byte *param_2,int param_3)

{
  byte bVar1;
  uint unaff_s1;
  uint uVar2;
  int iVar3;
  void *pvVar4;
  undefined4 unaff_s3;
  uint uVar5;
  byte bStack_23;
  ushort auStack_22 [5];
  
  if ((param_1 == 0) || (param_2 == (byte *)0x0)) {
    __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/zdo/zdo_dev_srv_disc.c",0x30d,
                  "zdo_op_simple_desc_rsp","payload && rsp");
  }
  else {
    if (param_3 == 0) {
      auStack_22[0] = 0;
      bStack_23 = 0;
      uVar5 = zmsg_get_length();
      af_read_le8(param_1,auStack_22,param_2);
      af_read_le16(param_1,auStack_22,param_2 + 2);
      af_read_le8(param_1,auStack_22,param_2 + 4);
      if ((int)uVar5 < (int)((uint)auStack_22[0] + (uint)param_2[4])) {
        return 0xfe;
      }
      if (*param_2 == 0) {
        af_read_le8(param_1,auStack_22,param_2 + 8);
        af_read_le16(param_1,auStack_22,param_2 + 10);
        af_read_le16(param_1,auStack_22,param_2 + 0xc);
        af_read_le8(param_1,auStack_22,&bStack_23);
        param_2[0xe] = param_2[0xe] & 0xf0 | bStack_23 >> 4;
        param_2[0xe] = (byte)((bStack_23 & 0xf) << 4) | bStack_23 >> 4;
        af_read_le8(param_1,auStack_22,param_2 + 0xf);
        bVar1 = param_2[0xf];
        pvVar4 = calloc((uint)bVar1,2);
        *(void **)(param_2 + 0x14) = pvVar4;
        uVar2 = 0;
        if (pvVar4 == (void *)0x0) {
          if (bVar1 != 0) {
            return 0x8a;
          }
          uVar2 = 0;
        }
        for (; uVar2 < param_2[0xf]; uVar2 = uVar2 + 1 & 0xff) {
          af_read_le16(param_1,auStack_22,*(int *)(param_2 + 0x14) + uVar2 * 2);
        }
        af_read_le8(param_1,auStack_22,param_2 + 0x10);
        iVar3 = mm_realloc(*(undefined4 *)(param_2 + 0x14),(uint)param_2[0xf] + (uint)param_2[0x10],
                           2);
        *(int *)(param_2 + 0x14) = iVar3;
        if ((iVar3 == 0) && ((uint)param_2[0xf] + (uint)param_2[0x10] != 0)) {
          return 0x8a;
        }
        for (uVar2 = (uint)param_2[0xf]; uVar2 < (uint)param_2[0xf] + (uint)param_2[0x10];
            uVar2 = uVar2 + 1 & 0xff) {
          af_read_le16(param_1,auStack_22,*(int *)(param_2 + 0x14) + uVar2 * 2);
        }
      }
      if (auStack_22[0] <= uVar5) {
        return 0;
      }
      return 0xfe;
    }
    auStack_22[0] = CONCAT11(auStack_22[0]._1_1_,*param_2);
    iVar3 = zmsg_append_bytes(1,auStack_22);
    if (iVar3 != 0) {
      return 0x8a;
    }
    auStack_22[0] = *(ushort *)(param_2 + 2);
    iVar3 = zmsg_append_bytes(param_1,2,auStack_22);
    if (iVar3 != 0) {
      return 0x8a;
    }
    unaff_s3 = zmsg_get_length(param_1);
    auStack_22[0] = CONCAT11(auStack_22[0]._1_1_,param_2[4]);
    iVar3 = zmsg_append_bytes(param_1,1,auStack_22);
    if (iVar3 != 0) {
      return 0x8a;
    }
    unaff_s1 = (uint)*param_2;
    if (unaff_s1 != 0) {
      return 0;
    }
  }
  bVar1 = param_2[4];
  param_2[4] = bVar1 + 1;
  param_2[4] = bVar1 + 3;
  param_2[4] = bVar1 + 5;
  param_2[4] = bVar1 + 6;
  param_2[4] = bVar1 + 8;
  auStack_22[0] = CONCAT11(auStack_22[0]._1_1_,param_2[8]);
  iVar3 = zmsg_append_bytes(param_1,1,auStack_22);
  if (iVar3 == 0) {
    auStack_22[0] = *(ushort *)(param_2 + 10);
    iVar3 = zmsg_append_bytes(param_1,2,auStack_22);
    if (iVar3 == 0) {
      auStack_22[0] = *(ushort *)(param_2 + 0xc);
      iVar3 = zmsg_append_bytes(param_1,2,auStack_22);
      if (iVar3 == 0) {
        auStack_22[0]._0_1_ =
             (byte)(*(uint *)(param_2 + 0xc) >> 0x14) & 0xf |
             (byte)((*(uint *)(param_2 + 0xc) >> 0x10 & 0xf) << 4);
        iVar3 = zmsg_append_bytes(param_1,1,auStack_22);
        if (iVar3 == 0) {
          auStack_22[0] = CONCAT11(auStack_22[0]._1_1_,param_2[0xf]);
          iVar3 = zmsg_append_bytes(param_1,1,auStack_22);
          uVar5 = unaff_s1;
          if (iVar3 == 0) {
            for (; uVar5 < param_2[0xf]; uVar5 = uVar5 + 1 & 0xff) {
              auStack_22[0] = *(ushort *)(*(int *)(param_2 + 0x14) + uVar5 * 2);
              iVar3 = zmsg_append_bytes(param_1,2,auStack_22);
              if (iVar3 != 0) {
                return 0x8a;
              }
              param_2[4] = param_2[4] + 2;
            }
            auStack_22[0] = CONCAT11(auStack_22[0]._1_1_,param_2[0x10]);
            iVar3 = zmsg_append_bytes(param_1,1,auStack_22);
            if (iVar3 == 0) {
              for (uVar5 = (uint)param_2[0xf]; uVar5 < (uint)param_2[0xf] + (uint)param_2[0x10];
                  uVar5 = uVar5 + 1 & 0xff) {
                auStack_22[0] = *(ushort *)(*(int *)(param_2 + 0x14) + uVar5 * 2);
                iVar3 = zmsg_append_bytes(param_1,2,auStack_22);
                if (iVar3 != 0) {
                  return 0x8a;
                }
                param_2[4] = param_2[4] + 2;
              }
              auStack_22[0] = CONCAT11(auStack_22[0]._1_1_,param_2[4]);
              zmsg_write_bytes(param_1,unaff_s3,1,auStack_22);
            }
            else {
              unaff_s1 = 0x8a;
            }
          }
          else {
            unaff_s1 = 0x8a;
          }
        }
        else {
          unaff_s1 = 0x8a;
        }
      }
      else {
        unaff_s1 = 0x8a;
      }
    }
    else {
      unaff_s1 = 0x8a;
    }
  }
  else {
    unaff_s1 = 0x8a;
  }
  return unaff_s1;
}

